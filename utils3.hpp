#ifndef _UTILS3_HPP
#define _UTILS3_HPP

// disable using namespace std in utils2
#define _UTILS2_HPP_NO_STD

#include "utils2.hpp"

namespace utils3 {


template <typename Cp, typename... Args>
Cp* class_factory(Args&&... args) 
noexcept(std::is_nothrow_constructible<Cp, Args...>::value)
{
  return new Cp(std::forward<Args>(args) ...);
}


// extend std::is_array
template <typename Tp>
struct is_array: public std::is_array<Tp> { };

template <typename Tp, size_t N>
struct is_array<std::array<Tp, N>> : public std::true_type { };

template <typename Tp>
struct is_array<std::vector<Tp>> : public std::true_type { };


// extend std::remove_extent
template <typename Tp>
struct remove_extent: public std::remove_extent<Tp> { };

template <typename Tp, size_t N>
struct remove_extent<std::array<Tp, N>> { typedef Tp type; };

template <typename Tp>
struct remove_extent<std::vector<Tp>> { typedef Tp type; };


// array cases
template <typename Tp> 
struct children_type : public remove_extent<Tp> { };

// handle unordered_map for some implementations of trie
template <typename Tp, typename Key>
struct children_type<std::unordered_map<Key, Tp>> { typedef Tp type; };


// is array (c or c++11) or std::vector of pointers
template <typename Tp>
struct is_array_of_pointers: 
  public std::__and_<
    is_array<Tp>,
    std::is_pointer<typename remove_extent<Tp>::type>
  >
{ };

// an alternative of using enum and index to represent graph types
// will reduce the definition of those helper tags
// while increase codes in other places (e.g. do_graph_category_impl)...
// thus, let's stick to this old-fashioned style

struct linked_list_tag { };
struct binary_tree_tag { };
struct quad_tree_tag { };
struct nary_tree_tag { };
// undirected
struct nary_graph_tag { };
// or has non-trivial destructor
struct single_node_tag { };

struct do_graph_category_impl {
  template <
    typename Tp,
    typename = typename std::enable_if<
      std::is_same<Tp, decltype(std::declval<Tp&>()->next)>::value
    >::type
  >
  static linked_list_tag test(int);

  template <
    typename Tp, 
    typename = typename std::enable_if<
      std::__and_<
        std::is_same<Tp, decltype(std::declval<Tp&>()->left)>,
        std::is_same<Tp, decltype(std::declval<Tp&>()->right)>
      >::value
    >::type
  >
  static binary_tree_tag test(long);

  template <
    typename Tp, 
    typename = typename std::enable_if<
      std::__and_<
        std::is_same<Tp, decltype(std::declval<Tp&>()->topLeft)>,
        std::is_same<Tp, decltype(std::declval<Tp&>()->topRight)>,
        std::is_same<Tp, decltype(std::declval<Tp&>()->bottomLeft)>,
        std::is_same<Tp, decltype(std::declval<Tp&>()->bottomRight)>
      >::value
    >::type
  >
  static quad_tree_tag test(long long);

  template <
    typename Tp, 
    typename = typename std::enable_if<
      std::is_same<
        Tp,
        typename children_type<decltype(std::declval<Tp&>()->children)>::type
      >::value
    >::type
  >
  static nary_tree_tag test(uint32_t);

  template <
    typename Tp,
    typename Up = decltype(std::declval<Tp&>()->neighbors),
    typename = typename std::enable_if<
      std::__and_<
        is_array<Up>,
        std::is_same<Tp, typename children_type<Up>::type>
      >::value
    >::type
  >
  static nary_graph_tag test(size_t);

  template <typename>
  static single_node_tag test(...);
};


template <typename Tp>
struct graph_category_impl: public do_graph_category_impl {
  typedef decltype(test<Tp>(0)) type;
};


// inherits graph category of Tp
template <typename Tp>
struct graph_category: public graph_category_impl<Tp>::type {
  typedef typename graph_category_impl<Tp>::type graph_category_tag;
};


// handle cyclic linked list
struct do_has_prev_impl {
  template <typename Tp, typename = decltype(std::declval<Tp>()->prev)>
  static std::true_type test(int);

  template <typename>
  static std::false_type test(...);
};

template <typename Tp>
struct has_prev_impl : public do_has_prev_impl {
  typedef decltype(test<Tp>(0)) type;
};

// whether the linked list node is doubly linked
template <typename Tp>
struct has_prev : public has_prev_impl<Tp>::type { };


// cut prev -> head link
template <typename Tp>
typename std::enable_if<
  has_prev<Tp*>::value
>::type
cut_prev(Tp* head) {
  if (head->prev)
    head->prev->next = nullptr;
}

// do nothing
template <typename Tp>
typename std::enable_if<
  !has_prev<Tp*>::value
>::type
cut_prev(Tp* ) { }


// single pointer
template <typename Tp>
void destroy_impl(Tp* ptr, single_node_tag) {
  if (ptr)
    delete ptr;
}


// linked list
template <typename Tp>
void destroy_impl(Tp* head, linked_list_tag) {
  cut_prev(head);

  Tp* p;
  while (head) {
    p = head->next;
    delete head;
    head = p;
  }
}


// binary tree
template <typename Tp>
void destroy_impl(Tp* root, binary_tree_tag tag) {
  if (!root)
    return;

  destroy_impl(root->left, tag);
  destroy_impl(root->right, tag);

  delete root;
}


// quad tree
template <typename Tp>
void destroy_impl(Tp* root, quad_tree_tag tag) {
  if (!root)
    return;

  destroy_impl(root->topLeft, tag);
  destroy_impl(root->topRight, tag);
  destroy_impl(root->bottomLeft, tag);
  destroy_impl(root->bottomRight, tag);

  delete root;
}


// general nary tree
template <typename Tp>
typename std::enable_if<
  is_array_of_pointers<
    decltype(std::declval<Tp*&>()->children)
  >::value
>::type
destroy_impl(Tp* root, nary_tree_tag tag) {
  if (!root)
    return;
  
  for (Tp* p : root->children)
    destroy_impl(p, tag);

  delete root;
}


// trie
template <typename Tp>
typename std::enable_if<
  !is_array_of_pointers<
    decltype(std::declval<Tp*&>()->children)
  >::value
>::type
destroy_impl(Tp* root, nary_tree_tag tag) {
  if (!root)
    return;
  
  for (auto& p : root->children)
    destroy_impl(p.second, tag);

  delete root;
}


// undirected graph
template <typename Tp>
void destroy_impl(Tp* root, nary_graph_tag tag) {
  if (!root)
    return;
  
  // for the purpose of coping with undirected cyclic graph
  // cut edges from neighbors to root
  // act as if the graph is directed
  for (Tp* p : root->neighbors) {
    if (p != nullptr) {
      // use auto and std::begin (end) to handle three types of arrays
      auto iter = std::find(std::begin(p->neighbors), std::end(p->neighbors), root);
      if (iter != std::end(p->neighbors))
        *iter = nullptr;
      else {
        std::cerr << "input undirected (a)cyclic graph is not well-defined" << std::endl;
        abort();
      }
    }
  }

  for (Tp* p : root->neighbors)
    destroy_impl(p, tag);

  delete root;
}

/**
 * @brief helper function for releasing memories
 * 
 * @tparam NodeType type that pointer root points to
 * 
 * @param root NodeType*
 * 
 */
template <typename NodeType> 
void destroy(NodeType* root) { 
  typedef typename std::remove_cv<NodeType>::type no_cv_nodetype;

  destroy_impl(
    const_cast<no_cv_nodetype*>(root), 
    graph_category<no_cv_nodetype*>{}
  ); 
}

// do nothing for non-pointer types
// specializations to handle 
// pointers / vector of pointers / ...
template<typename Tp>
struct universal_destroyer {
  void operator()(Tp&) {
    // do nothing...
  }
};

template <typename Tp>
struct universal_destroyer<Tp*> {
  void operator()(Tp* ptr) {
    destroy(ptr);
  }
};

template <typename Tp>
struct universal_destroyer<std::vector<Tp*>> {
  void operator()(std::vector<Tp*>& vec) {
    for (Tp* ptr : vec)
      destroy(ptr);
  }
};

template <typename Tp>
struct universal_destroyer<std::vector<std::vector<Tp*>>> {
  void operator()(std::vector<std::vector<Tp*>>& mat) {
    for (auto& vec : mat)
      for (Tp* ptr : vec)
        destroy(ptr);
  }
};


TreeNode* find_node_in_arbitrary_tree(TreeNode* root, int val) {
  if (!root)
    return nullptr;
  else if (root->val == val)
    return root;

  TreeNode* node = find_node_in_arbitrary_tree(root->left, val);

  return node ? node : find_node_in_arbitrary_tree(root->right, val);
}


TreeNode* find_node_in_bst(TreeNode* root, int val) {
  if (!root)
    return nullptr;

  if (root->val > val)
    return find_node_in_bst(root->left, val);
  else if (root->val < val)
    return find_node_in_bst(root->right, val);
  else
    return root;
}


// find a tree node given root and value
TreeNode* find_node_in_tree(TreeNode* root, int val, bool is_bst = false) {
  return is_bst ? find_node_in_bst(root, val) : find_node_in_arbitrary_tree(root, val);
}


// find a linked list node given head and value
ListNode* find_node_in_linked_list(ListNode* head, int val) {
  while (head && head->val != val)
    head = head->next;

  return head;
}


// helper traits
// different from the one in std lib
template <typename Tp> struct is_scalar : public std::true_type { };

template <> struct is_scalar<std::string> : public std::false_type { };
template <typename Tp> struct is_scalar<std::vector<Tp>> : public std::false_type { };
template <typename Tp> struct is_scalar<Tp*> : public std::false_type { };


template <typename Tp> struct is_quoted : public std::false_type { };
template <> struct is_quoted<std::string> : public std::true_type { };

template <
  typename Tp, 
  bool Is_Scalar = is_scalar<Tp>::value,
  bool Is_String = std::is_same<Tp, std::string>::value
>
struct find_end_of_arg_impl;

template <typename Tp>
struct find_end_of_arg_impl<Tp, true, false> {
  void operator()(size_t& j, const std::string& s) {
    while (j < s.size() && s[j] != ' ' && s[j] != ',' && s[j] != ';')
      ++j;
  }
};

template <typename Tp>
struct find_end_of_arg_impl<Tp, false, false> {
  void operator()(size_t& j, const std::string& s) {
    const size_t n = s.size();
    // find left most '['
    for (; j < n && s[j] != '['; ++j);

    // find right most ']'
    int count = 1;
    for (++j; j < n && count > 0; ++j) {
      if (s[j] == '[')
        ++count;
      else if (s[j] == ']')
        --count;
    }
  }
};

// handle ',' inside of string
template <typename Tp>
struct find_end_of_arg_impl<Tp, false, true> {
  void operator()(size_t& j, const std::string& s) {
    const size_t n = s.size();
    // find left '"'
    for (; j < n && s[j] != '"'; ++j);

    // find right '"'
    for (++j; j < n && s[j] != '"'; ++j);

    // to include last '"'
    ++j;
  }
};

/*
// is_scalar = true
inline void find_end_of_arg(size_t& j, const std::string& s, std::true_type) {
  while (j < s.size() && s[j] != ' ' && s[j] != ',' && s[j] != ';')
    ++j;
}

// is_scalar = false
inline void find_end_of_arg(size_t& j, const std::string& s, std::false_type) {
  size_t n = s.size();
  // find left most '['
  for (; j < n && s[j] != '['; ++j);

  // find right most ']'
  int count = 1;
  for (++j; j < n && count > 0; ++j) {
    if (s[j] == '[')
      ++count;
    else if (s[j] == ']')
      --count;
  }
}
*/


/**
 * @brief parse string (list of lists of arguments) to vector of string
 * 
 * @param s string, list of lists of arguments of calls to be parsed
 * 
 * @return std::vector\\<std::string> 
 */
std::vector<std::string> parse_argss(const std::string& s) {
  const size_t n = s.size();

  size_t j = 0;
  while (j < n && s[j] != '[')
    ++j;

  std::vector<std::string> out;
  while (j < n) {
    // skip ',' or leftmost '['
    ++j;

    // skip other spaces
    while (j < n && s[j] != '[')
      ++j;

    size_t i = j + 1;
    // find_end_of_arg(j, s, std::false_type{});
    find_end_of_arg_impl<std::vector<std::string>>()(j, s);

    if (j < n) 
      out.push_back(s.substr(i, j - i - 1)); // remove '^[' and ']$'
  }

  return out;
}


// parse from left to right
template <typename Tp>
inline Tp universal_parser_helper(size_t& j , const std::string& s) {
  while (j < s.size() && (s[j] == ' ' || s[j] == ',' || s[j] == ';'))
    ++j;

  size_t i = j;
  // find_end_of_arg(j, s, is_scalar<Tp>{});
  find_end_of_arg_impl<Tp>()(j, s);

  return utils2::universal_parser<Tp>()(s.substr(i, j - i));
}



template <typename Tuple, std::size_t... Is>
void input_gen(Tuple& params, 
               const std::string& s, 
               std::index_sequence<Is...>) {
  // ...
  // j is a global index of s, indicating end of an argument
  size_t j = 0;
  (
    (std::get<Is>(params) = 
      universal_parser_helper<
        typename std::tuple_element_t<Is, Tuple>::type // tuple_element_t<> = input_parameter
      >(j, s)
    ), 
    ...
  );
}


template <typename Cp>
class MethodClassBase {
  private:
    typedef MethodClassBase<Cp> self;
    typedef Cp class_type;

  public:
    virtual std::string getName() const = 0;

    virtual double operator()(class_type*, const std::string&) const = 0;

    virtual self* clone() const = 0;

    virtual ~MethodClassBase() { }
};


template <class MemFn>
class MethodClass : public MethodClassBase<typename utils2::fn_ptr_traits<MemFn>::class_type> {
  public:
    typedef MemFn mem_fn_ptr;
    typedef typename utils2::fn_ptr_traits<MemFn>::class_type class_type;
    typedef typename utils2::fn_ptr_traits<MemFn>::return_type return_type;
    typedef typename utils2::fn_ptr_traits<MemFn>::args_tuple_param_type args_tuple_param_type;

    typedef MethodClassBase<class_type> base;
    typedef MethodClass<mem_fn_ptr> self;
    
    constexpr static const size_t args_size = utils2::fn_ptr_traits<MemFn>::value;

  private:
    std::string name;

    mem_fn_ptr fn;

    // void return type
    template <typename Tp = return_type, size_t... Is>
    typename std::enable_if<std::is_void<Tp>::value, double>::type 
    ufunc_call(class_type* ptr, 
               args_tuple_param_type& params, 
               std::index_sequence<Is...>) const {
      // ...
      std::chrono::time_point<std::chrono::system_clock> start( std::chrono::system_clock::now() );

      (ptr->*fn)(std::get<Is>(params) ...);

      std::chrono::time_point<std::chrono::system_clock> end( std::chrono::system_clock::now() );
      std::chrono::duration<double, std::milli> elapsed( end - start );


// in case nontrivial default ctor of Solution is unavoidable 
#ifndef _NONTRIVIAL_SOLUTION_CTOR
      // differentiate ufuncx and ufuncs by verifying 
      // whether class_type is trivially default constructible
      if constexpr (!std::is_trivially_default_constructible<class_type>::value)
        std::cout << "null";
      else
#endif
        utils2::universal_print<
          typename std::tuple_element_t<0, args_tuple_param_type>::type
        >()(std::get<0>(params));

      return elapsed.count();
    }

    // non-void return type
    template <typename Tp = return_type, size_t... Is>
    typename std::enable_if<!std::is_void<Tp>::value, double>::type 
    ufunc_call(class_type* ptr, 
               args_tuple_param_type& params, 
               std::index_sequence<Is...>) const {
      // ...
      std::chrono::time_point<std::chrono::system_clock> start( std::chrono::system_clock::now() );

      return_type res = (ptr->*fn)(std::get<Is>(params) ...);

      std::chrono::time_point<std::chrono::system_clock> end( std::chrono::system_clock::now() );
      std::chrono::duration<double, std::milli> elapsed( end - start );


// in case nontrivial default ctor of Solution is unavoidable 
#ifndef _NONTRIVIAL_SOLUTION_CTOR
      // tackle non-scalar return type when printing results
      // differentiate ufuncx and ufuncs by verifying
      // whether class_type is trivially default constructible
      if constexpr (!std::is_trivially_default_constructible<class_type>::value && utils2::is_2d<return_type>::value) {
        std::cout << "\n ";
        // print 2D array flatly
        utils2::universal_print<return_type, false>()(res);
      }
      else
#endif
        utils2::universal_print<return_type>()(res);

// in case returned pointer type should be deleted here
// to avoid memory leak error
#ifdef _DELETE_RETURN_POINTER
      universal_destroyer<return_type>()(res);
#endif

      return elapsed.count();
    }

  public:
    MethodClass(mem_fn_ptr _fn, const std::string& _nm)
      : fn(_fn), name(_nm) { }

    virtual std::string getName() const override { return name; }

    virtual double operator()(class_type* ptr, const std::string& s) const override {
      args_tuple_param_type params;

      input_gen(params, s, std::make_index_sequence<args_size>{});

      // only const member functions can be called inside const member function
      return ufunc_call(ptr, params, std::make_index_sequence<args_size>{});
    }

    virtual self* clone() const override { return new self(*this); }

    virtual ~MethodClass() { }
};


/**
 * @brief wraps everything (factory and method) up
 * 
 * @tparam Func type of function pointer to class factory
 * 
 */
template <class Func>
class Wrapper {
  private:
    typedef Wrapper<Func> self;
    typedef Func class_factory_ptr;
    typedef typename std::remove_pointer<
      typename utils2::fn_ptr_traits<Func>::return_type
    >::type class_type;

    typedef typename utils2::fn_ptr_traits<Func>::args_tuple_param_type args_tuple_param_type;
    constexpr static const size_t args_size = utils2::fn_ptr_traits<Func>::value;

    // in many cases the arguments of ctor have to live
    // at least as long as the object they created
    args_tuple_param_type inputs;

    // pointer to class used in all methods
    class_type* ptr;

    class_factory_ptr fn;
    std::vector<MethodClassBase<class_type>*> methods;

    template <size_t... Is>
    void factory_helper(std::index_sequence<Is...>) {
      ptr = (*fn)(std::get<Is>(inputs) ...);
    }

    void release_object() {
      if (ptr)
        delete ptr; 
    }

    void release_memory() {
      release_object();

      // be careful of memory leak...
      for (auto m : methods)
        if (m) delete m;

      methods.clear();
    }

  public:
    Wrapper() = delete;

    explicit Wrapper(Func _fn): ptr(nullptr), fn(_fn) { }

    Wrapper(const self& x): fn(x.fn), inputs(x.inputs) {
      static_assert(std::is_copy_constructible<class_type>::value, "copy ctor not available");

      ptr = new class_type(*x.ptr);
      for (auto m : x.methods) 
        methods.push_back(m->clone());
    }

    self& operator=(const self& x) {
      static_assert(std::is_copy_constructible<class_type>::value, "copy ctor not available");

      release_memory();

      fn = x.fn;
      inputs = x.inputs;

      ptr = new class_type(*(x.ptr));
      for (auto m : x.methods) 
        methods.push_back(m->clone());
    }

    // manage pointer carefully
    Wrapper(self&& x)
      noexcept(std::is_move_constructible<args_tuple_param_type>::value)
      : ptr(x.ptr), inputs(std::move(x.inputs)), fn(x.fn) {
      // ...
      x.ptr = nullptr;
      swap(methods, x.methods);
    }

    self& operator=(self&& x)
      noexcept(std::is_move_assignable<args_tuple_param_type>::value) {
      // ...
      fn = x.fn;
      inputs = std::move(x.inputs);
      
      swap(ptr, x.ptr);
      swap(methods, x.methods);
    }

    self& initializeOrReplace(const std::string& s = "") {
      release_object();

      input_gen(inputs, s, std::make_index_sequence<args_size>{});
      
      factory_helper(std::make_index_sequence<args_size>{});

      return *this;
    }

    template <typename Tp, typename... Args>
    self& addMethod(Tp (class_type::*fn)(Args...), const std::string& s) {
      methods.push_back(
        new MethodClass<Tp (class_type::*)(Args...)>(fn, s)
      );
      return *this;
    }

    double callMethod(const std::string& name, const std::string& args) {
      MethodClassBase<class_type>* method = nullptr;
      for (auto m : methods)
        if (m->getName() == name) {
          method = m;
          break;
        }

      if (!method) {
        std::cerr << "class method " << name << " is not found (added)";
        abort();
      }
      
      return method->operator()(ptr, args);
    }

    ~Wrapper() { release_memory(); }
};


// check if all Types are the same
template <typename... Types> struct all_same;

template <typename Tp>
struct all_same<Tp> : public std::true_type { typedef Tp type; };

template <typename Tp, typename Up, typename... Types>
struct all_same<Tp, Up, Types...> : public std::false_type { };

template <typename Tp, typename... Types>
struct all_same<Tp, Tp, Types...> : public all_same<Tp, Types...> { };


/**
 * @brief construct class by specified ctor and call methods by
 * parsing the input file located at path as parameters (and method names)
 * 
 * @tparam Args argument types for a specific ctor, 
 *   must be explicitly specified (no deduction available from parameters)
 * @tparam MemFns pointers to member functions
 * 
 * @param path path to input file
 * @param method_names member function names generated by MACRO #__VA_ARGS__
 * @param mem_fns pointers to member functions
 * 
 */
template <typename... Args, typename... MemFns>
void ufuncx(const std::string& path,
            const std::string& method_names,
            MemFns... mem_fns) {
  // ...
  // also works as enable_if
  // type is not defined 
  // if member functions do not belong to the same class
  typedef typename all_same<
    typename utils2::fn_ptr_traits<MemFns>::class_type ...
  >::type class_type;

  static_assert(std::is_constructible<class_type, Args...>::value, "no specified ctor exists!");

  typedef class_type* (*factory_type)(Args&& ...);

  factory_type factory = class_factory<class_type, Args ...>;

  // parse method names by regex iterator
  std::regex re("&(\\w+)::(\\w+)");
  std::sregex_iterator iter(method_names.begin(), method_names.end(), re);

  std::string class_name = iter->str(1);

  // although template deduction works,
  // explicit typing helps static compiler...
  Wrapper<factory_type> w(factory);

  // add methods and names to wrapper (feature since c++17)
  // skip class name matches
  ( w.addMethod(mem_fns, iter++->str(2)), ... );

  std::ifstream f(path);
  std::string line;
  double exec_time = 0; // execution time
  while (getline(f, line)) {

    // parse input file (methods and arguments)
    size_t j = 0;
    // find_end_of_arg(j, line, std::false_type{});
    find_end_of_arg_impl<std::vector<std::string>>()(j, line);
    auto methods = utils2::universal_parser<std::vector<std::string>>()(line.substr(0, j));

    std::vector<std::string> argss = parse_argss(line.substr(j));

    w.initializeOrReplace(argss.front());

    // ctor prints nothing
    std::cout << "[null" << std::flush;

    for (size_t i = 1; i < methods.size(); ++i) {
      std::cout << ", ";
      exec_time += w.callMethod(methods[i], argss[i]);
      std::cout << std::flush;
    }

    std::cout << ']' << std::endl;

  } // end of while loop

  std::cout << "****** Execution time of `" << class_name  \
  << "` is: " << exec_time << " milliseconds. ******" << std::endl;
}


template <typename MemFn>
void ufuncs(const std::string& path,
            const std::string& method_name_raw,
            MemFn mem_fn) {
  // ...

  typedef typename utils2::fn_ptr_traits<MemFn>::class_type class_type;
  // assert default ctor
  static_assert(std::is_default_constructible<class_type>::value, "no default ctor");

  typedef class_type* (*factory_type)();

  factory_type factory = class_factory<class_type>;

  // although template deduction works,
  // explicit typing helps static compiler...
  Wrapper<factory_type> w(factory);

  // parse method name
  std::string method_name = 
    method_name_raw.substr(method_name_raw.find_last_of(':') + 1);

  // create instance and add method and name to wrapper
  w.initializeOrReplace().addMethod(mem_fn, method_name);

  std::ifstream f(path);
  std::string line;
  double exec_time = 0; // execution time
  while (getline(f, line)) {

    exec_time += w.callMethod(method_name, line);

    std::cout << std::endl;

  } // end of while loop

  std::cout << "****** Execution time of `" << method_name \
  << "` is: " << exec_time << " milliseconds. ******" << std::endl;
}


} // end of namespace utils3


#define CTOR(...) __VA_ARGS__


/**
 * @brief ctro argument types and variable lengths of class methods needed
 * 
 */
#define UFUNCX(CTOR_ARGS, ...) \
  utils3::ufuncx<CTOR_ARGS>( \
    "Inputs/" + utils2::to_txt_file(__FILE__), \
    #__VA_ARGS__, __VA_ARGS__ \
  )


/**
 * @brief updated version of UFUNC... 
 * a special case of UFUNCX... 
 * 
 * no & before member function pointer is 
 * for the purpose of following predecessor
 * 
 */
#define UFUNCS_BASE(METHOD) \
  utils3::ufuncs( \
    "Inputs/" + utils2::to_txt_file(__FILE__), \
    #METHOD, &METHOD \
  )


/**
 * @brief explicitly specify the type of member function pointer
 *   to handle override correctly
 * 
 */
#define UFUNCR_BASE(METHOD, RETURN, ARGS) \
  utils3::ufuncs<RETURN (Solution::*) ARGS>( \
    "Inputs/" + utils2::to_txt_file(__FILE__), \
    #METHOD, &METHOD \
  )

#define UFUNCR_NOARGS(METHOD, RETURN) UFUNCR_BASE(METHOD, RETURN, ());

#define GETUFUNC(DUMMY1, DUMMY2, DUMMY3, NAME, ...) NAME

#define UFUNCS(...) GETUFUNC(__VA_ARGS__, UFUNCR_BASE, UFUNCR_NOARGS, UFUNCS_BASE) (__VA_ARGS__)

using namespace std;

#endif // end of _UTILS_HPP