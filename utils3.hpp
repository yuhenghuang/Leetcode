#ifndef _UTILS3_HPP
#define _UTILS3_HPP

// disable using namespace std in utils2
#define _UTILS2_HPP_NO_STD

#include "utils2.hpp"

namespace utils3 {


template <typename Tp, typename... Types>
Tp* class_factory(Types&&... args) {
  return new Tp(std::forward<Types>(args) ...);
}

// helper traits
// different from the one in std lib
template <typename Tp> struct is_scalar : public std::true_type { };

template <typename Tp> struct is_scalar<std::vector<Tp>> : public std::false_type { };
template <> struct is_scalar<TreeNode*> : public std::false_type { };
template <> struct is_scalar<ListNode*> : public std::false_type { };

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


/**
 * @brief parse string (list of lists of arguments) to vector of string
 * 
 * @param s string, list of lists of arguments of calls to be parsed
 * 
 * @return std::vector\\<std::string> 
 */
std::vector<std::string> parse_argss(const std::string& s) {
  size_t n = s.size();

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
    find_end_of_arg(j, s, std::false_type{});

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
  find_end_of_arg(j, s, is_scalar<Tp>{});

  return utils2::universal_parser<Tp>()(s.substr(i, j - i));
}



template <typename Tuple, std::size_t... Is>
void input_gen(Tuple& params, 
               const std::string& s, 
               std::index_sequence<Is...>) {
  // ...
  // j is a global index of s
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


template <typename Tp>
class MethodClassBase {
  private:
    typedef MethodClassBase<Tp> self;
    typedef Tp class_type;

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

    template <size_t... Is>
    double ufun_call(class_type* ptr, 
                     args_tuple_param_type& params, 
                     std::true_type, 
                     std::index_sequence<Is...>) const {
      // void type
      std::chrono::time_point<std::chrono::system_clock> start( std::chrono::system_clock::now() );

      (ptr->*fn)(std::get<Is>(params) ...);

      std::chrono::time_point<std::chrono::system_clock> end( std::chrono::system_clock::now() );
      std::chrono::duration<double, std::milli> elapsed( end - start );

      std::cout << "null";

      return elapsed.count();
    }

    template <size_t... Is>
    double ufun_call(class_type* ptr, 
                     args_tuple_param_type& params, 
                     std::false_type, 
                     std::index_sequence<Is...>) const {
      // non-void type
      std::chrono::time_point<std::chrono::system_clock> start( std::chrono::system_clock::now() );

      return_type res = (ptr->*fn)(std::get<Is>(params) ...);

      std::chrono::time_point<std::chrono::system_clock> end( std::chrono::system_clock::now() );
      std::chrono::duration<double, std::milli> elapsed( end - start );

      utils2::universal_print<return_type>()(res);

      return elapsed.count();
    }

  public:
    MethodClass(mem_fn_ptr _fn, const std::string& _nm)
      : fn(_fn), name(_nm) { }

    virtual std::string getName() const { return name; }

    virtual double operator()(class_type* ptr, const std::string& s) const {
      args_tuple_param_type params;

      input_gen(params, s, std::make_index_sequence<args_size>{});

      // only const member functions can be called inside const member function
      return ufun_call(
        ptr,
        params, 
        std::is_void<return_type>{}, 
        std::make_index_sequence<args_size>{}
      );
    }

    virtual self* clone() const { return new self(*this); }

    virtual ~MethodClass() { }
};


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

    // pointer used in all methods
    class_type* ptr;

    class_factory_ptr fn;
    std::vector<MethodClassBase<class_type>*> methods;

    template <size_t... Is>
    void factoryHelper(std::index_sequence<Is...>) {
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
      ptr = new class_type(*x.ptr);
      for (auto m : x.methods) 
        methods.push_back(m->clone());
    }

    self& operator=(const self& x) {
      release_memory();

      ptr = new class_type(*x.ptr);
      for (auto m : x.methods) 
        methods.push_back(m->clone());

      fn = x.fn;
      inputs = x.inputs;
    }

    // manage pointer carefully
    Wrapper(self&& x): ptr(x.ptr), inputs(std::move(x.inputs)), fn(x.fn) {
      x.ptr = nullptr;
      swap(methods, x.methods);
    }

    self& operator=(self&& x) {
      swap(ptr, x.ptr);
      swap(methods, x.methods);

      fn = x.fn;
      inputs = std::move(x.inputs);
    }

    void initializeOrReplace(const std::string& s) {
      release_object();

      input_gen(inputs, s, std::make_index_sequence<args_size>{});
      
      factoryHelper(std::make_index_sequence<args_size>{});
    }

    template <typename Ret, typename... Args>
    self& addMethod(Ret (class_type::*fn)(Args...), const std::string& s) {
      methods.push_back(
        new MethodClass<Ret (class_type::*)(Args...)>(fn, s)
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
      
      return method ? method->operator()(ptr, args) : 0.0;
    }

    ~Wrapper() { release_memory(); }
};

/**
 * @brief construct class by factory and call methods by
 * parsing the input file located at path as parameters (and method names)
 * 
 * @tparam Func pointer to class factory function
 * @tparam MemFns pointers to member functions
 * 
 * @param path path to input file
 * @param factory pointer to class factory function
 * @param method_names_raw member function names generated by MACRO #__VA_ARGS__
 * @param mem_fns pointers to member functions
 * 
 */
template <typename Func, typename... MemFns>
void ufuncx(const std::string& path,
            Func factory,
            const std::string& method_names_raw,
            MemFns... mem_fns) {
  // ...
  // parse method names
  std::vector<std::string> method_names;
  std::istringstream iss(method_names_raw);
  std::string name;
  while (getline(iss, name, ',')) {
    method_names.push_back(
      name.substr(name.find_last_of(':') + 1)
    );
  }

  // although template deduction works,
  // explicit typing helps static compiler...
  Wrapper<Func> w(factory);

  // add methods and names to wrapper
  std::vector<std::string>::iterator iter = method_names.begin();
  ( w.addMethod(mem_fns, *iter++), ... );

  std::ifstream f(path);
  std::string line;
  double exec_time = 0; // execution time
  while (getline(f, line)) {

    // parse input file (methods and arguments)
    size_t j = 0;
    find_end_of_arg(j, line, std::false_type{});
    std::vector<std::string> methods = 
      utils2::universal_parser<std::vector<std::string>>()(line.substr(0, j));

    std::vector<std::string> argss = parse_argss(line.substr(j));

    w.initializeOrReplace(argss.front());

    // ctro prints nothing
    std::cout << "[null";

    for (size_t i = 1; i < methods.size(); ++i) {
      std::cout << ", ";
      exec_time += w.callMethod(methods[i], argss[i]);
    }

    std::cout << ']' << std::endl;

  } // end of while loop

  std::cout << "****** Execution time of `" << \
  method_names_raw.substr(1, method_names_raw.find_first_of(':') - 1)  \
  << "` is: " << exec_time << " milliseconds. ******" << std::endl;
}


template <typename Func, typename MemFn>
void ufuncs(const std::string& path,
            Func factory,
            const std::string& method_name_raw,
            MemFn mem_fn) {
  // ...
  // parse method name
  std::string method_name = 
    method_name_raw.substr(method_name_raw.find_last_of(':') + 1);

  // although template deduction works,
  // explicit typing helps static compiler...
  Wrapper<Func> w(factory);

  // add method and name to wrapper
  w.addMethod(mem_fn, method_name);

  w.initializeOrReplace("");

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


#define FACTORY(...) utils3::class_factory<__VA_ARGS__>

/**
 * @brief 
 * 
 * class_factory is a conventional name!!! plz stick to this function pointer name.
 * 
 */
#define UFUNCX(FUNC, ...) \
  utils3::ufuncx( \
    "Inputs/" + utils2::to_txt_file(__FILE__), \
    FUNC, #__VA_ARGS__, __VA_ARGS__ \
  );


/**
 * @brief updated version of UFUNC... 
 * a special case of UFUNCX... 
 * 
 * no & before member function pointer is 
 * for the purpose of following predecessor
 * 
 */
#define UFUNCS(METHOD) \
  utils3::ufuncs( \
    "Inputs/" + utils2::to_txt_file(__FILE__), \
    FACTORY(Solution), #METHOD, &METHOD \
  );



using namespace std;

#endif