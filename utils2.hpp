#ifndef _UTILS2_HPP
#define _UTILS2_HPP

#include "DataStructure.h"

#include <sstream>
#include <iostream>
#include <iterator>
#include <queue>
#include <bits/stdc++.h>
#include <type_traits>
#include <stack>
#include <fstream>

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
// default is 2D horizontally
#ifndef PRINT_TREE_1D
template <>
struct is_2d<TreeNode*> : public std::true_type { };
#endif

// parse inputs

template <typename Tp, bool Is_2D = is_2d<Tp>::value>
struct universal_parser;

template <>
struct universal_parser<std::string> {
  std::string operator()(const std::string& str) {
    return str;
  }
};


template <>
struct universal_parser<int> {
  int operator()(const std::string& str) {
    return stoi(str);
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
    return str[0];
  }
};


template <>
struct universal_parser<TreeNode*> {
  TreeNode* operator()(const std::string& str) {
    std::string line = regex_replace(str, std::regex("[\\[\\]\\s\"]+"), "");

    TreeNode* root = nullptr;
    TreeNode* node;
    
    std::queue<TreeNode*> q;
    bool left = true;

    std::istringstream ss(line);
    std::string val;
    while (getline(ss, val, ',')) {
      node = (val.compare("null")==0) ? nullptr : new TreeNode(stoi(val));

      if (node)
        q.push(node);
      
      if (root==nullptr) {
        root = node;
      }
      else {
        if (left)
          q.front()->left = node;
        else {
          q.front()->right = node;
          q.pop();
        }
        left = !left;
      }
    }

    return root;
  }
};


template <>
struct universal_parser<ListNode*> {
  ListNode* operator()(const std::string& str) {
    ListNode* root = nullptr;
    ListNode* prev, * next;

    std::string line = regex_replace(str, std::regex("[\\[\\]\\s\"]+"), "");
    std::istringstream ss(line);
    std::string val;
    while (getline(ss, val, ',')) {
      next = new ListNode(stoi(val));
      if (root==nullptr) {
        prev = next;
        root = prev;
      }
      else {
        prev->next = next;
        prev = next;
      }
    }

    return root;
  }
};


template <typename Tp>
struct universal_parser<std::vector<Tp>, false> {
  std::vector<Tp> operator()(const std::string& str) {
    std::string line = regex_replace(str, std::regex("[\\[\\]\\s\"]+"), "");

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
    std::string line = regex_replace(str, std::regex("\\s+"), "");
    line = regex_replace(line, std::regex("\\],\\["), ";");

    std::vector<Tp> out;
    // empty 2d vector
    if (line.size()==2) return out;

    universal_parser<Tp> parser;

    std::istringstream ss(line);
    std::string row;
    while (getline(ss, row, ';'))
      out.push_back(parser(row));

    return out;
  }
};


// print results

template <typename Tp>
struct is_element : public std::true_type { };

template <typename Tp>
struct is_element<std::vector<std::vector<Tp>>> : public std::true_type { };

template <>
struct is_element<ListNode*> : public std::false_type { };

template <typename Tp>
struct is_element<std::vector<Tp>> : public std::false_type { };

// add line end if tree is set to print in 1D
#ifdef PRINT_TREE_1D
template <>
struct is_element<TreeNode*> : public std::false_type { };
#endif

template <typename Tp, bool Is_2D = is_2d<Tp>::value>
struct universal_print {
  void operator()(const Tp res) {
    std::cout << res << std::endl;
  }
};


template <>
struct universal_print<bool> {
  void operator()(const bool res) {
    std::cout << std::boolalpha << res << std::endl;
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

    std::queue<TreeNode*> q;
    if (root) {
      std::cout << root->val;
      if (root->left || root->right) {
        q.push(root->left);
        q.push(root->right);
      }
    }

    while (q.size()>1 || (q.size()==1 && q.front())) {
      std::cout << ", ";

      root = q.front();
      q.pop();

      if (root) {
        std::cout << root->val;
        if (root->left || root->right) {
          q.push(root->left);
          q.push(root->right);
        }
      }
      else
        std::cout << "null";
    }

    std::cout << ']';
  }
};



template <typename Tp>
struct universal_print<std::vector<Tp>, false> {
  void operator()(const std::vector<Tp>& res) {
    size_t n=res.size();

    std::cout << "[";
    for (size_t i=0; i<n; ++i) {
      std::cout << res[i];
      if (i+1<n)
        std::cout << ", ";
    }
    std::cout << "]";
  }
};


// TreeNode* is also adjusted for the specialization
template <typename Tp>
struct universal_print<std::vector<Tp>, true> {
  void operator()(const std::vector<Tp>& res) {
    size_t n = res.size();
    universal_print<Tp, false> print;

    std::cout << "[";
    for (size_t i=0; i<n; ++i) {
      if (i>0)
        std::cout << "\\s";

      print(res[i]);
      
      if (i<n-1)
        std::cout << ',' << std::endl;
    }
    std::cout << "]" << std::endl;
  }
};


std::vector<std::string> string_split(const std::string& str, char delim=';') {
  std::vector<std::string> out;

  std::istringstream ss(str);
  std::string part;

  while (getline(ss, part, delim)) {
    part = regex_replace(part, std::regex("\"|\\s+"), "");
    out.push_back(std::move(part));
  }

  return out;
}

std::string to_txt_file(const std::string& path) {
  std::string file = path.substr(path.find_last_of('/')+1);
  file.replace(file.size()-3, 3, "txt");
  return file;
}

template <typename... Args>
struct args_pack { };

template <typename MemFn>
struct mem_fn_traits;

template <class Tp, typename Ret, typename... Args>
struct mem_fn_traits<Ret (Tp::*)(Args...)>
  : public std::integral_constant<size_t, sizeof...(Args)> {
  // ...
  typedef Tp class_type;
  typedef Ret return_type;
  typedef args_pack<Args...> args_type;
  typedef std::tuple<
    typename std::remove_cv<
      typename std::remove_reference<Args>::type
    >::type ...
  > args_tuple_type;
};


template <class MemFn>
class bind_obj_impl {
  public:
    typedef MemFn mem_fn_ptr;
    typedef typename mem_fn_traits<MemFn>::class_type Tp;
    typedef typename mem_fn_traits<MemFn>::return_type Ret;

  protected:
    mem_fn_ptr fn;
    Tp* obj_ptr;

  public:
    bind_obj_impl(mem_fn_ptr _fn, Tp* _obj_ptr): fn(_fn), obj_ptr(_obj_ptr) { }

    // works for both void and non-void return type
    template <typename... Types>
    Ret operator()(Types&& ...args) {
      return (obj_ptr->*fn)(std::forward<Types>(args) ...);
    }
};


template <class MemFn>
bind_obj_impl<MemFn>
bind_obj(MemFn fn, typename mem_fn_traits<MemFn>::class_type& obj) {
  return bind_obj_impl<MemFn>(fn, &obj);
}


template <typename Tuple, std::size_t... Is>
void input_gen(Tuple& params, 
               std::vector<std::string>::iterator iter, 
               std::index_sequence<Is...>) {
  // ...
  (
    (std::get<Is>(params) = 
      universal_parser<
        std::tuple_element_t<Is, Tuple>
      >()(*iter++)
    ), 
    ...
  );
}


template <class MemFn, typename Tuple, std::size_t... Is>
std::enable_if_t<
  !std::is_void<
    typename mem_fn_traits<MemFn>::return_type
  >::value
> 
ufunc_call(bind_obj_impl<MemFn>& functor,
           Tuple& params,
           double& exec_time,
           std::index_sequence<Is...>) {
  // ...

  typedef typename mem_fn_traits<MemFn>::return_type Ret;

  std::chrono::time_point<std::chrono::system_clock> start( std::chrono::system_clock::now() );

  Ret res = functor(std::get<Is>(params) ...);

  std::chrono::time_point<std::chrono::system_clock> end( std::chrono::system_clock::now() );
  std::chrono::duration<double, std::milli> elapsed( end - start );
  exec_time += elapsed.count();

  universal_print<Ret>()(res);

  // new line for 1D vector, Tree and LinkedList
  if constexpr (!is_element<Ret>::value)
    std::cout << std::endl;
}


template <class MemFn, typename Tuple, std::size_t... Is>
std::enable_if_t<
  std::is_void<
    typename mem_fn_traits<MemFn>::return_type
  >::value
> 
ufunc_call(bind_obj_impl<MemFn>& functor,
           Tuple& params,
           double& exec_time,
           std::index_sequence<Is...>) {
  // ...
  typedef std::tuple_element_t<0, Tuple> Arg0;

  std::chrono::time_point<std::chrono::system_clock> start( std::chrono::system_clock::now() );

  functor(std::get<Is>(params) ...);

  std::chrono::time_point<std::chrono::system_clock> end( std::chrono::system_clock::now() );
  std::chrono::duration<double, std::milli> elapsed( end - start );
  exec_time += elapsed.count();

  universal_print<Arg0>()(std::get<0>(params));

  if constexpr (!is_element<Arg0>::value)
    std::cout << std::endl;
}


template <class MemFn>
void ufunc(bind_obj_impl<MemFn>& functor,
           std::string& line, 
           double& exec_time) {
  // ...

  // arguments to vector<string>
  std::vector<std::string> args = string_split(line);

  // tuple of arguments without reference
  typename mem_fn_traits<MemFn>::args_tuple_type params;

  input_gen(params, args.begin(), std::make_index_sequence<mem_fn_traits<MemFn>::value>{});

  ufunc_call(functor, params, exec_time, std::make_index_sequence<mem_fn_traits<MemFn>::value>());
}


} // end of utils2


using namespace std;


#define UFUNC(method) \
  Solution sol; \
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


#endif