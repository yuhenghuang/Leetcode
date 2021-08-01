#ifndef _UTILS2_HPP
#define _UTILS2_HPP

#include "DataStructure.h"

#include <sstream>
#include <iostream>
#include <iterator>
#include <queue>
#include <regex>
#include <type_traits>
#include <stack>
#include <fstream>
#include <climits>

namespace utils2 {

template <typename Tp>
struct is_2d : public std::false_type { };

template <typename Tp>
struct is_2d<std::vector<std::vector<Tp>>> : public std::true_type { };

template <>
struct is_2d<std::vector<ListNode*>> : public std::true_type { };

template <>
struct is_2d<std::vector<TreeNode*>> : public std::true_type { };

// for indicating print tree in 1D or 2D
// default is 1D horizontally
#ifdef PRINT_TREE_2D
template <>
struct is_2d<TreeNode*> : public std::true_type { };
#endif

// parse inputs

template <typename Tp, bool Is_2D = is_2d<Tp>::value>
struct universal_parser;

template <>
struct universal_parser<std::string> {
  std::string operator()(const std::string& str) {
    // remove quotes
    return str.substr(1, str.size() - 2);
  }
};


template <>
struct universal_parser<int> {
  int operator()(const std::string& str) {
    return stoi(str);
  }
};


template <>
struct universal_parser<uint32_t> {
  uint32_t operator()(const std::string& str) {
    uint32_t res = 0;

    for (char c : str) {
      res <<= 1;
      res |= c-'0';
    }

    return res;
  }
};


template <>
struct universal_parser<double> {
  double operator()(const std::string& str) {
    return stod(str);
  }
};


template <>
struct universal_parser<char> {
  char operator()(const std::string& str) {
    // skip '\'' at index 0
    return str[1];
  }
};


template <>
struct universal_parser<TreeNode*> {
  TreeNode* operator()(const std::string& str) {
    std::string line = regex_replace(str, std::regex("[\\[\\]\\s]+"), "");

    if (line.size() == 0)
      return nullptr;

    // size of tree
    size_t n = std::count(line.begin(), line.end(), ',') + 1UL;

    // size of null node
    size_t u = std::count(line.begin(), line.end(), 'u');

    // only array new non-null nodes
    // prepare for further plan of memory management (smart pointer)
    TreeNode* root = new TreeNode[n - u];

    // iterator over non-null nodes
    TreeNode* node = root;

    // array of null and non-null nodes in the order of input
    TreeNode* nodes[n];

    // iterator over nodes
    TreeNode** iter;

    std::istringstream ss(line);
    std::string val;
    for (iter = &nodes[0]; getline(ss, val, ','); ++iter) {
      if (val != "null") {
        node->val = stoi(val);
        *iter = node++;
      }
      else
        *iter = nullptr;
    }

    iter = &nodes[0];
    bool left = true;
    for (size_t i = 1; i < n; ++i) {
      // this loop is always valid because it runs slower than `i`
      while (*iter == nullptr)
        ++iter;

      if (left)
        (*iter)->left = nodes[i];
      else 
        (*iter++)->right = nodes[i];

      left = !left;
    }

    return root;
  }
};


template <>
struct universal_parser<ListNode*> {
  ListNode* operator()(const std::string& str) {
    std::string line = regex_replace(str, std::regex("[\\[\\]\\s]+"), "");

    if (line.size() == 0)
      return nullptr;

    // size of linked list
    size_t n = std::count(line.begin(), line.end(), ',') + 1UL;

    // array new to save memory
    // prepare for further plan of memory management (smart pointer)
    ListNode* root = new ListNode[n];

    ListNode* node = root;

    std::istringstream ss(line);
    std::string val;

    for (size_t i = 0; i < n; ++i, ++node) {
      getline(ss, val, ',');
      node->val = stoi(val);

      if (i < n - 1) 
        node->next = node + 1;
    }

    return root;
  }
};


template <typename Tp>
struct universal_parser<std::vector<Tp>, false> {
  std::vector<Tp> operator()(const std::string& str) {
    std::string line = regex_replace(str, std::regex("^\\s*\\[\\s*"), "");
    line = regex_replace(line, std::regex("\\s*\\]\\s*$"), "");
    line = regex_replace(line, std::regex("\\s*,\\s*"), ",");

    size_t n = std::count(line.begin(), line.end(), ',') + 1;

    std::vector<Tp> out;
    out.reserve(n);

    universal_parser<Tp> parser;

    std::istringstream ss(line);
    std::string element;

    while (getline(ss, element, ','))
      out.push_back(parser(element));

    return out;
  }
};


template <typename Tp>
struct universal_parser<std::vector<Tp>, true> {
  std::vector<Tp> operator()(const std::string& str) {
    // remove "[" and "]" in the start and end
    std::string line = regex_replace(str, std::regex("^\\s*\\[\\s*"), "");
    line = regex_replace(line, std::regex("\\s*\\]\\s*$"), "");

    // "],[" as delimiter for 2D arrays
    line = regex_replace(line, std::regex("\\s*\\]\\s*,\\s*\\[\\s*"), ";");

    std::vector<Tp> out;

    if (line.size() == 0) 
      return out;

    universal_parser<Tp> parser;

    std::istringstream ss(line);
    std::string row;
    while (getline(ss, row, ';'))
      out.push_back(parser(row));

    return out;
  }
};


struct do_is_printable_impl {
  template <typename Tp, typename = decltype(std::cout << std::declval<Tp&>())>
  static std::true_type test(int);

  template <typename>
  static std::false_type test(...);
};

template <typename Tp>
struct is_printable_impl: public do_is_printable_impl {
  typedef decltype(test<Tp>(0)) type;
};

// is operator<< defined?
template <typename Tp>
struct is_printable : 
  public std::__and_<
    typename is_printable_impl<Tp>::type,
    std::__not_<std::is_pointer<Tp>>
  >
{ };


// print results
template <typename Tp, bool Is_2D = is_2d<Tp>::value>
struct universal_print {
  // flag to help only print info once
  inline static bool flag = true;

  template <typename Up = Tp>
  typename std::enable_if<!is_printable<Up>::value>::type
  operator()(const Tp&) {
    // ...
    if (flag) {
      std::cout << "no available function/operator<< to print the result\n" \
        << "please define the specialization of universal_print<> by yourself if you'd like";
      flag = false;
    }
  }

  template <typename Up = Tp>
  typename std::enable_if<is_printable<Up>::value>::type
  operator()(const Tp res) {
    std::cout << res;
  }
};


template <>
struct universal_print<char> {
  void operator()(const std::string& res) {
    std::cout << '\'' << res << '\'';
  }
};


template <>
struct universal_print<std::string> {
  void operator()(const std::string& res) {
    std::cout << '\"' << res << '\"';
  }
};


template <>
struct universal_print<bool> {
  void operator()(const bool res) {
    std::cout << std::boolalpha << res;
  }
};


template <>
struct universal_print<ListNode*> {
  void operator()(ListNode* head) {
    std::cout << "[";

    if (head) {
      while (head->next) {
        std::cout << head->val << ", ";
        head = head->next;
      }
      std::cout << head->val;
    }
    
    std::cout << "]";
  }
};


void print_tree_horizontal(const TreeNode* root, bool is_left=false, const std::string& prefix="") {
  if (root) {
    std::cout << prefix;
    std::cout << (is_left ? "|-- " : "\\-- ");
    std::cout << root->val << std::endl;
    print_tree_horizontal(root->left, true, prefix + (is_left ? "|   " : "    "));
    print_tree_horizontal(root->right, false, prefix + (is_left ? "|   " : "    "));
  }
}

template <>
struct universal_print<TreeNode*, true> {
  void operator()(TreeNode* root) {
    print_tree_horizontal(root);
  }
};


template <>
struct universal_print<TreeNode*, false> {
  void operator()(TreeNode* root) {
    std::cout << '[';

    // count of non-null nodes in current and next level
    int m, n = 0;

    std::queue<TreeNode*> q;
    if (root) {
      std::cout << root->val;

      if (root->left) ++n;
      if (root->right) ++n;

      q.push(root->left);
      q.push(root->right);
    }


    while (!q.empty()) {
      m = n;
      n = 0;

      int N = q.size();
      while (N--) {
        root = q.front();
        q.pop();

        if (root) {
          --m;

          std::cout << ", " << root->val;

          if (root->left) ++n;
          if (root->right) ++n;

          q.push(root->left);
          q.push(root->right);
        }
        else if (m>0 || n>0)
          std::cout << ", null";
      }

    }

    std::cout << ']';
  }
};


#ifdef QUAD_NODE

template <>
struct universal_print<Node*, false> {
  void operator()(Node* root) {
    std::cout << '[';

    // count of non-null nodes in current and next level
    int m, n = 0;

    std::queue<Node*> q;
    if (root) {
      std::cout << "[" << root->isLeaf \
        << ", " << root->val << ']';

      if (root->topLeft) ++n;
      if (root->topRight) ++n;
      if (root->bottomLeft) ++n;
      if (root->bottomRight) ++n;

      q.push(root->topLeft);
      q.push(root->topRight);
      q.push(root->bottomLeft);
      q.push(root->bottomRight);
    }

    while (!q.empty()) {
      m = n;
      n = 0;

      int N = q.size();
      while (N--) {
        root = q.front();
        q.pop();

        if (root) {
          --m;

          std::cout << ", [" << root->isLeaf \
            << ", " << root->val << ']';

          if (root->topLeft) ++n;
          if (root->topRight) ++n;
          if (root->bottomLeft) ++n;
          if (root->bottomRight) ++n;

          q.push(root->topLeft);
          q.push(root->topRight);
          q.push(root->bottomLeft);
          q.push(root->bottomRight);
        }
        else if (m > 0 || n > 0)
          std::cout << ", null";
      }
    }

    std::cout << ']';
  }
};

#endif // end of QUAD_NODE


template <typename Tp>
struct universal_print<std::vector<Tp>, false> {
  void operator()(const std::vector<Tp>& res) {
    size_t n = res.size();
    universal_print<Tp> print;

    std::cout << '[';
    for (size_t i = 0; i < n; ++i) {
      print(res[i]);

      if (i < n - 1)
        std::cout << ", ";
    }
    std::cout << ']';
  }
};


// TreeNode* is also adjusted for the specialization
template <typename Tp>
struct universal_print<std::vector<Tp>, true> {
  void operator()(const std::vector<Tp>& res) {
    size_t n = res.size();
    universal_print<Tp, false> print;

    std::cout << '[';
    for (size_t i = 0; i < n; ++i) {
      if (i > 0)
        std::cout << ' ';

      print(res[i]);
      
      if (i < n - 1)
        std::cout << ',' << std::endl;
    }
    std::cout << ']';
  }
};


std::vector<std::string> string_split(const std::string& str, char delim=';') {
  std::vector<std::string> out;

  std::istringstream ss(str);
  std::string part;

  while (getline(ss, part, delim)) {
    // remove spaces in the start and end
    part = regex_replace(part, std::regex("^\\s+|\\s+$"), "");
    out.push_back(std::move(part));
  }

  return out;
}


std::string to_txt_file(const std::string& path) {
  std::string file = path.substr(path.find_last_of('/')+1);
  // replace ext by .txt
  file = regex_replace(file, std::regex("\\..*$"), ".txt");
  return file;
}


// check if Tp is a vector of pointers
template <typename Tp>
struct is_vector_of_pointers_impl: public std::false_type { };

template <typename Tp>
struct is_vector_of_pointers_impl<std::vector<Tp*>>: public std::true_type { };

template <typename Tp>
struct is_vector_of_pointers: 
  public is_vector_of_pointers_impl<
    typename std::remove_cv<
      typename std::remove_reference<Tp>::type
    >::type
  > {

};


// remove const in pointer
template <typename Tp>
struct remove_const_pointer {
  typedef Tp type;
};

template <typename Tp>
struct remove_const_pointer<Tp*> {
  typedef typename std::remove_const<Tp>::type* type;
};


// apply cv lvalue reference
// from clang std

template <bool ApplyLV, bool ApplyConst, bool ApplyVolatile>
struct apply_cv_mf;

template <>
struct apply_cv_mf<false, false, false> {
  template <class T> using apply = T;
};

template <>
struct apply_cv_mf<true, false, false> {
  template <class T> using apply = T&;
};

template <>
struct apply_cv_mf<true, true, false> {
  template <class T> using apply = const T&;
};

template <>
struct apply_cv_mf<true, false, true> {
  template <class T> using apply = volatile T&;
};

template <>
struct apply_cv_mf<true, true, true> {
  template <class T> using apply = const volatile T&;
};


template <>
struct apply_cv_mf<false, true, false> {
  template <class T> using apply = const T;
};

template <>
struct apply_cv_mf<false, false, true> {
  template <class T> using apply = volatile T;
};

template <>
struct apply_cv_mf<false, true, true> {
  template <class T> using apply = const volatile T;
};

// apply const, volatile and lreference
template <class T, class Raw = typename std::remove_reference<T>::type>
using apply_cv_t = apply_cv_mf<
                     std::is_lvalue_reference<T>::value,
                     std::is_const<Raw>::value,
                     std::is_volatile<Raw>::value
                   >;


/* memo:
Although it's possible to implement vector versions by recursion, 
currently feasible ideas will result in considerable amount of 
unnecessary copies during implicit conversion in practice.

It's gone far beyond the scope when the input parameters are actually
quite limited (only three types, i.e. primitive types, lvalue reference and pointer).
The necessity to handle rvalue reference, const properly and 
to collect garbage in heap memory (in case of pointers) is
in fact not really significant.

If might not be a good idea to make GP infinitely general...
bear this in mind
*/

template <typename Tp, bool Is_Vector_of_Pointers = is_vector_of_pointers<Tp>::value>
class input_parameter;


// wrapper of input parameters
// for non-pointer types (including references and const)
template <typename Tp>
class input_parameter<Tp, false> {
  public:
    typedef typename std::remove_const<
      typename std::remove_reference<Tp>::type
    >::type type;

  private:
    typedef input_parameter<Tp, false> self;

    type par;

  public:
    input_parameter() = default;

    input_parameter(self&& x) 
      noexcept(std::is_move_constructible<type>::value): par(std::move(x.par)) { }
    self& operator=(self&& x) 
      noexcept(std::is_move_assignable<type>::value) { par = std::move(x.par); }

    inline operator Tp() {
      /*
      par is lvalue before cast.

      if Tp is non-reference type, then copy construction (not move because par is lvalue) 
      will be called to create a new object of Tp as prvalue since c++17.

      > For non-reference new_type, the result object of the static_cast 
      > prvalue expression is what's direct-initialized.

      this behavior is to be expected and
      compiler will optimize redandunt copy constructions
      (copy construction will happen only once)
      */
      return static_cast<Tp>(par);
    }

    template <
      typename Up,
      typename = typename std::enable_if<std::is_assignable<type&, Up&&>::value>::type
    >
    self& operator=(Up&& _par)
    noexcept(std::is_nothrow_assignable<type&, Up&&>::value) {
      par = std::forward<Up>(_par);

      return *this;
    }
};


// for pointers (of objects saved in heap)
template <typename Tp>
class input_parameter<Tp*, false> {
  public:
    typedef typename std::remove_const<Tp>::type* type;

  private:
    typedef input_parameter<Tp*, false> self;

    type par;

    void release_memory() {
      if (par != nullptr)
        delete[] par;
    }

  public:
    // copy ctor / assignment is not supported
    // because copy of tree / linkedlist is undefined
    input_parameter(const self&) = delete;
    self& operator=(const self&) = delete;

    input_parameter(): par(nullptr) { }

    input_parameter(self&& x) noexcept: par(x.par) { x.par = nullptr; }
    self& operator=(self&& x) noexcept { swap(par, x.par); }

    inline operator Tp*() {
      return par;
    }


    // ~~TODO: support polymorphis~~
    // Done!
    template <
      typename Up,
      typename = typename std::enable_if<std::is_assignable<type&, Up&&>::value>::type
    >
    self& operator=(Up&& _par)
    noexcept(std::is_nothrow_assignable<type&, Up&&>::value) {
      release_memory();

      par = std::forward<Up>(_par);

      return *this;
    }

    ~input_parameter() {
      release_memory();
    }
};


// for vector of pointers
// ~~TODO: how to generalize the const and ref of vector~~
// ~~TODO: how to handle const pointer?~~
// Done! Done!
// This approach can be generalized to all types of arrays, with the help of array adapter.
template <typename Tp>
class input_parameter<Tp, true> {
  private:
    typedef typename std::remove_reference<Tp>::type::value_type pointer;
    typedef typename remove_const_pointer<pointer>::type nonconst_pointer;

    typedef input_parameter<Tp, true> self;

    std::vector<pointer> par;

    void release_memory() {
      for (pointer ptr : par)
        if (ptr != nullptr)
          delete[] ptr;
    }

  public:
    // type is not the type of par
    // in order to be in line with parser
    typedef std::vector<nonconst_pointer> type;

    input_parameter() = default;

    input_parameter(const self&) = delete;
    self& operator=(const self&) = delete;

    // no need to handle memory at ctor
    input_parameter(self&& x) noexcept : par(std::move(x.par)) {  }
    self& operator=(self&& x) noexcept { par.swap(x.par); }

    inline operator Tp() {
      return static_cast<Tp>(par);
    }

    template <
      typename Up,
      typename std::enable_if<std::is_assignable<std::vector<pointer>&, Up&&>::value, bool>::type = true
    >
    self& operator=(Up&& _par) 
    noexcept(std::is_nothrow_assignable<std::vector<pointer>&, Up&&>::value) {
      if (!par.empty())
        release_memory();

      par = std::forward<Up>(_par);

      return *this;
    }

    // over load when Up&& is not assignable but elements are constructible (or assignable?)
    // Future work: differentiate copy and move construction of elements
    template <
      typename Up,
      typename Element = typename std::remove_reference<Up>::type::value_type,
      typename std::enable_if<
        !std::is_assignable<std::vector<pointer>&, Up&&>::value
        &&
        std::is_constructible<
          pointer, 
          typename apply_cv_t<Up>::template apply<Element>&&
        >::value,
        bool
      >::type = false
    >
    self& operator=(Up&& _par) 
    noexcept(
      std::is_nothrow_constructible<
        pointer, 
        typename apply_cv_t<Up&&>::template apply<Element>&&
      >::value
    ) {
      if (!par.empty())
        release_memory();

      using element_type = typename apply_cv_t<Up>::template apply<Element>&&;

      par.clear();
      par.reserve(_par.size());
      for (auto& e : _par)
        par.emplace_back(static_cast<element_type>(e));

      return *this;
    }

    ~input_parameter() {
      release_memory();
    }
};


template <typename... Args> struct args_pack { };


template <typename Tp>
struct remove_rvalue_reference {
  typedef Tp type;
};

template <typename Tp>
struct remove_rvalue_reference<Tp&&> {
  typedef Tp type;
};


template <bool... Preds> struct bool_dummies { };

template <bool... Preds>
struct all
  : public std::is_same<bool_dummies<Preds...>, bool_dummies<((void)Preds, true)...>> { };


template <class From, class To> struct args_convertible;

template <typename... Types, typename... Args>
struct args_convertible<args_pack<Types...>, args_pack<Args...>> 
  : public all<
    std::is_convertible<Types, Args>::value ...
  >
{ };


// function / class member function traits
template <typename MemFn> struct fn_ptr_traits;

// specialization for member function
template <typename Tp, class Cp, typename... Args>
struct fn_ptr_traits<Tp (Cp::*)(Args...)>
  : public std::integral_constant<size_t, sizeof...(Args)> {
  // ...
  typedef Tp return_type;
  typedef Cp class_type;
  typedef args_pack<Args...> args_type;

  typedef std::tuple<
    typename std::remove_cv<
      typename std::remove_reference<Args>::type
    >::type ...
  > args_tuple_type;

  // reference must be removed before removing const and volatile
  typedef std::tuple<input_parameter<Args> ...> args_tuple_param_type;

};

// for normal function
template <typename Tp, typename... Args>
struct fn_ptr_traits<Tp (*)(Args...)>
  : public std::integral_constant<size_t, sizeof...(Args)> {
  // ...
  typedef Tp return_type;
  typedef args_pack<Args...> args_type;

  // deprecated
  // reference must be removed before removing const and volatile
  typedef std::tuple<
    typename std::remove_cv<
      typename std::remove_reference<Args>::type
    >::type ...
  > args_tuple_type;

  typedef std::tuple<input_parameter<Args> ...> args_tuple_param_type;
};


template <class MemFn>
class bind_obj_impl {
  public:
    typedef bind_obj_impl<MemFn> self;
    typedef MemFn mem_fn_ptr;
    typedef typename fn_ptr_traits<MemFn>::class_type class_type;
    typedef typename fn_ptr_traits<MemFn>::return_type return_type;
    typedef typename fn_ptr_traits<MemFn>::args_type args_type;

  protected:
    mem_fn_ptr fn;
    class_type* obj_ptr;

  private:
    template <class MF> friend 
    bind_obj_impl<MF> bind_obj(MF, typename fn_ptr_traits<MF>::class_type*);

    bind_obj_impl(mem_fn_ptr _fn, class_type* _obj_ptr): fn(_fn), obj_ptr(_obj_ptr) { }

  public:
    bind_obj_impl(const self&) = delete;
    self& operator=(const self&) = delete;

    bind_obj_impl(self&& x): fn(x.fn), obj_ptr(x.obj_ptr) { x.obj_ptr = nullptr; }
    self& operator=(self&& x) { fn = x.fn; swap(obj_ptr, x.obj_ptr); }

    // works for both void and non-void return type
    template <typename... Types>
    typename std::enable_if<
      args_convertible<args_pack<Types&& ...>, args_type>::value,
      return_type
    >::type
    operator()(Types&& ...args) {
      // ...
      return (obj_ptr->*fn)(std::forward<Types>(args) ...);
    }

    ~bind_obj_impl() {
      if (obj_ptr)
        delete obj_ptr;
    }
};


template <class MemFn>
bind_obj_impl<MemFn>
bind_obj(MemFn fn, typename fn_ptr_traits<MemFn>::class_type* obj) {
  return bind_obj_impl<MemFn>(fn, obj);
}


template <typename Tuple, std::size_t... Is>
void input_gen(Tuple& params, 
               std::vector<std::string>::iterator iter, 
               std::index_sequence<Is...>) {
  // ...
  (
    (std::get<Is>(params) = 
      universal_parser<
        typename std::tuple_element_t<Is, Tuple>::type // tuple_element_t<> = input_parameter
      >()(*iter++)
    ), 
    ...
  );
}


template <class Functor, typename Tuple, std::size_t... Is>
std::enable_if_t<
  !std::is_void<
    typename Functor::return_type
  >::value
> 
ufunc_call(Functor& functor,
           Tuple& params,
           double& exec_time,
           std::index_sequence<Is...>) {
  // ...

  typedef typename Functor::return_type return_type;

  std::chrono::time_point<std::chrono::system_clock> start( std::chrono::system_clock::now() );

  return_type res = functor(std::get<Is>(params) ...);

  std::chrono::time_point<std::chrono::system_clock> end( std::chrono::system_clock::now() );
  std::chrono::duration<double, std::milli> elapsed( end - start );
  exec_time += elapsed.count();

  universal_print<return_type>()(res);

  // new line for 1D vector, Tree and LinkedList
  // if constexpr (!is_element<Ret>::value)
  std::cout << std::endl;
}


template <class Functor, typename Tuple, std::size_t... Is>
std::enable_if_t<
  std::is_void<
    typename Functor::return_type
  >::value
> 
ufunc_call(Functor& functor,
           Tuple& params,
           double& exec_time,
           std::index_sequence<Is...>) {
  // ...
  typedef typename std::tuple_element_t<0, Tuple>::type Arg0;

  std::chrono::time_point<std::chrono::system_clock> start( std::chrono::system_clock::now() );

  functor(std::get<Is>(params) ...);

  std::chrono::time_point<std::chrono::system_clock> end( std::chrono::system_clock::now() );
  std::chrono::duration<double, std::milli> elapsed( end - start );
  exec_time += elapsed.count();

  universal_print<Arg0>()(std::get<0>(params));

  // if constexpr (!is_element<Arg0>::value)
  std::cout << std::endl;
}


template <class MemFn>
void ufunc(bind_obj_impl<MemFn>& functor,
           std::string& line, 
           double& exec_time) {
  // ...

  // arguments to vector<string>
  std::vector<std::string> args = string_split(line);

  // tuple of arguments wrapped by input_parameter class
  typename fn_ptr_traits<MemFn>::args_tuple_param_type params;

  input_gen(params, args.begin(), std::make_index_sequence<fn_ptr_traits<MemFn>::value>{});

  ufunc_call(functor, params, exec_time, std::make_index_sequence<fn_ptr_traits<MemFn>::value>{});
}


} // end of namespace utils2


// for downward compatibility that utils2 can work by itself
#ifndef _UTILS2_HPP_NO_STD
using namespace std;
#endif


#define UFUNC(method) \
  Solution* sol = new Solution(); \
  auto functor = utils2::bind_obj(&method, sol); \
  string path = "Inputs/" + utils2::to_txt_file(__FILE__);  \
  double exec_time = 0; \
  ifstream f(path); \
  string line; \
  while (getline(f, line)) { \
    utils2::ufunc(functor, line, exec_time); \
  } \
  cout << "****** Execution time of `" << \
  string(#method).substr(10) << "` is: " << \
  exec_time << " milliseconds. ******" << endl;


#endif // end of _UTILS2_HPP