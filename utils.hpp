#ifndef _UTILS_HPP
#define _UTILS_HPP

#include "DataStructure.h"

#include <sstream>
#include <iostream>
#include <iterator>
#include <queue>
#include <bits/stdc++.h>
#include <type_traits>
#include <fstream>


namespace utils {

  template<typename T>
  T trans(std::string& str) {
    return str;
  }

  template<>
  int trans(std::string& str) {
    return stoi(str);
  }

  template<>
  char trans(std::string& str) {
    return str[0];
  }

  template<>
  double trans(std::string& str) {
    return stod(str);
  }

  /**
   * @brief Parse string to 1D vector, e.g. "[3,2,7]", white spaces allowed.
   * 
   * @tparam T typename, current supports int, double, char, std::string
   * 
   * @exception TypeNotSupported
   * 
   */
  template<typename T>
  struct parse_vector_1d {
    /**
     * @brief Parse string to 1D vector
     * 
     * @param line Serialized string of a 1D vector, e.g. "[3,7,9]", white spaces allowed.
     * @return std::vector<T> T was defined when functor constructed.
     */
    std::vector<T> operator()(std::string& row) {
      std::vector<T> out;
      row = regex_replace(row, std::regex("[\\[\\]\\s\"]+"), "");
      std::istringstream ss(row);

      std::string element;
      while (getline(ss, element, ',')) {
        out.push_back(trans<T>(element));
      }

      return out;
    }
  };
  
  /**
   * @brief Parse string to 2D vector, e.g. "[[3,2,7],[3,7,9],[8,3,9]]", white spaces allowed.
   * 
   * @tparam T typename, current supports int, double, char, std::string
   * 
   */
  template<typename T>
  struct parse_vector_2d {
    /**
     * @brief Parse string to 2D vector
     * 
     * 
     * @param line Serialized string of a 2D vector, e.g. "[[3,2,7],[3,7,9],[8,3,9]]", white spaces allowed.
     * 
     * @return std::vector<std::vector<T>> T was defined when functor constructed.
     */
    std::vector<std::vector<T>> operator()(std::string& line) {
      line = regex_replace(line, std::regex("\\s+"), "");
      line = regex_replace(line, std::regex("\\],\\["), ";");

      std::vector<std::vector<T>> out;
      // empty 2d vector
      if (line.size()==2) return out;

      std::istringstream ss(line);
      parse_vector_1d<T> parser;

      std::string row;
      while (getline(ss, row, ';')) {
          out.push_back(parser(row));
      }

      return out;
    } 
  };

  /**
   * @brief Parse string to Tree
   * 
   * 
   * @param line Serialized string of a tree, e.g. "[1, NULL, 2]" white space allowed.
   * 
   * @return TreeNode* root
   */
  TreeNode *parse_tree(std::string& line) {
    TreeNode* root = nullptr;
    TreeNode* node;
    std::queue<TreeNode*> q;

    line = regex_replace(line, std::regex("[\\[\\]\\s\"]+"), "");
    std::istringstream ss(line);
    std::string val;
    bool left=true;
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

  /**
   * @brief Parse string to linked list.
   * 
   * 
   * @param line Serialized string of a linked list, e.g. "[1, 3, 2]" white space allowed.
   * 
   * @return ListNode* head
   */
  ListNode *parse_linked_list(std::string& line) {
    ListNode* root = nullptr;
    ListNode* prev, * next;

    line = regex_replace(line, std::regex("[\\[\\]\\s\"]+"), "");
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


  /**
   * @brief Split string by delimiter `char`, e.g. "substring a ; substring b"
   * 
   * @param str std::string, consists of multiple arguments, partitioned by a certain delimiter
   * @param delim char, ';' by default
   * 
   * @return std::vector\\<std::string> 
   */
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


  /**
   * @brief Print linked list
   * 
   * 
   * @param head Linked list node pointer
   * 
   */
  void print_linked_list(ListNode* head) {
    std::cout << "[";

    if (head) {
      while (head->next) {
        std::cout << head->val << ", ";
        head = head->next;
      }
      std::cout << head->val;
    }
    
    std::cout << "]" << std::endl;
  }


  /**
   * @brief print 1D vector
   * 
   * @tparam T typename of std::vector<T>, operator<< must be defined for T
   * 
   * @param res const std::vector<T>&
   * 
   */
  template<typename T>
  void print_vector_1d(const std::vector<T>& res) {
    int n=res.size();

    std::cout << "[";
    for (int i=0; i<n; ++i) {
      std::cout << res[i];
      if (i<n-1)
        std::cout << ", ";
    }
    std::cout << "]" << std::endl;
  }


  /**
   * @brief print 2D vector
   * 
   * @tparam T typename of std::vector<std::vector<T>>, operator<< must be defined for T
   * 
   * @param res const std::vector<std::vector<T>>&
   * 
   */
  template<typename T>
  void print_vector_2d(const std::vector<std::vector<T>>& res) {
    int n=res.size();

    std::cout << "[";
    for (int i=0; i<n; ++i) {
      if (i>0)
        std::cout << " ";

      print_vector_1d(res[i]);
      
      if (i<n-1)
        std::cout << "," << std::endl;
    }
    std::cout << "]" << std::endl;

  }

  /**
   * @brief Print binray tree horizontally in terminal
   * 
   * 
   * @param root Root of the tree
   * @param is_left Flag of indicating left or right
   * @param prefix String printed before value, please use default
   * 
   */
  void print_tree_horizontal(const TreeNode* root, bool is_left=false, const std::string& prefix="") {
    if (root) {
      std::cout << prefix;
      std::cout << (is_left ? "|-- " : "\\-- ");
      std::cout << root->val << std::endl;
      print_tree_horizontal(root->left, true, prefix + (is_left ? "|   " : "    "));
      print_tree_horizontal(root->right, false, prefix + (is_left ? "|   " : "    "));
    }
  }



  // universal parser
  template<typename T>
  struct universal_parser {
    T operator()(std::string& str) {
      return trans<T>(str);
    }
  };

  template<>
  TreeNode* trans(std::string& str) {
    return parse_tree(str);
  }

  template<>
  ListNode* trans(std::string& str) {
    return parse_linked_list(str);
  }

  template<typename T>
  struct universal_parser<std::vector<T>> {
    std::vector<T> operator()(std::string& str) {
      return parse_vector_1d<T>()(str);
    }
  };

  template<typename T>
  struct universal_parser<std::vector<std::vector<T>>> { 
    std::vector<std::vector<T>> operator()(std::string& str) {
      return parse_vector_2d<T>()(str);
    }
  };


  // universal printer
  template<typename T>
  void universal_print(T res) {
    std::cout << res << std::endl;
  }

  template<>
  void universal_print(bool res) {
    std::cout << std::boolalpha << res << std::endl;
  }

  template<typename T>
  void universal_print(const std::vector<T>& res) {
    print_vector_1d(res);
  }

  template<typename T>
  void universal_print(const std::vector<std::vector<T>>& res) {
    print_vector_2d(res);
  }

  template<>
  void universal_print(TreeNode* root) {
    print_tree_horizontal(root);
  }

  template<>
  void universal_print(ListNode* root) {
    print_linked_list(root);
  }


  // input parameters
  template <typename T>
  class input_parameter {
    private:
      std::string& str;
    public:
      input_parameter(std::string& _s): str(_s) { }

      inline operator T() { return universal_parser<T>()(str); }
  };

  template <typename T>
  class input_parameter<T&> {
    public:
      typedef T& reference;
      typedef const T& const_ref;
      input_parameter(std::string& _s) {
        data = universal_parser<T>()(_s);
      }

      inline operator reference() { return data; }

      // for print purpose, not necessary
      inline operator const_ref() { return data; }

    private:
      T data;
  };

  template <typename T>
  class input_parameter<T*> {
    public:
      typedef T* pointer;
      input_parameter(std::string& _s) {
        data = universal_parser<pointer>()(_s);
      }
      ~input_parameter() {
        delete data;
      }

      // inline operator pointer() { return &data; }
      inline operator pointer() { return data; }

    private:
      // T data
      pointer data;
  };

  template <typename T>
  class input_parameter<const T&> {
    public:
      typedef const T& const_ref;
      input_parameter(std::string& _s) {
        data = universal_parser<T>()(_s);
      }

      inline operator const_ref() { return data; }

    private:
      T data;
  };

  template <typename T>
  class input_parameter<const T> {
    public:
      typedef const T const_nonref;
      input_parameter(std::string& _s) {
        data = universal_parser<T>()(_s);
      }

      inline operator const_nonref() { return data; }

    private:
      T data;
  };

  // auto-generated, deprecated
  #include "utils_generated_py.hpp"

  /**
   * @brief parse __FILE__ to filename with "txt" ext.
   * 
   * @param path __FILE__
   * 
   * @return std::string, filename with "txt" extension name.
   */
  std::string to_txt_file(const std::string& path) {
    std::string file = path.substr(path.find_last_of('/')+1);
    file.replace(file.size()-3, 3, "txt");
    return file;
  }
}

// construction complete
#if __cplusplus >= 201403L // impl. of ufunc

namespace utils {

  /* out-dated

  // generate tuple type
  // mostly remove const and reference
  template <typename T=void, typename... Types>
  struct tuple_type_gen {
    typedef typename tuple_type_gen<Types...>::type rest;

    typedef std::remove_reference_t<std::remove_cv_t<T>> _Tp;
    using type = decltype(
      std::tuple_cat(
        std::declval<std::tuple<_Tp>>(),
        std::declval<rest>()
      )
    );
  };

  template <>
  struct tuple_type_gen<> {
    typedef std::tuple<> type;
  };
  */

#if __cplusplus >= 201703L

  // ... use c++17 features, very convinient and fictional.
  template <typename Tuple, std::size_t... Is>
  void input_gen(Tuple& params, std::vector<std::string>::iterator iter, std::index_sequence<Is...>) {
    (
      (std::get<Is>(params) = 
        universal_parser<std::tuple_element_t<Is,Tuple>>()(*iter++)
      ), 
      ...
    );
  }

#else

  // put the end condition of the recursions first!!!
  // the order matters!!!
  template <size_t N, typename... Types>
  std::enable_if_t< N == sizeof...(Types) > 
  input_gen(std::tuple<Types...>& params, 
            std::vector<std::string>::iterator iter) { }

  template <size_t N = 0, typename... Types>
  std::enable_if_t< N < sizeof...(Types) > 
  input_gen(std::tuple<Types...>& params, 
            std::vector<std::string>::iterator iter) {

    // assign to tuple recursively
    std::get<N>(params) = universal_parser<
                            std::tuple_element_t<
                              N, 
                              std::remove_reference_t<decltype(params)>
                              >
                            >()(*iter);
    input_gen<N+1, Types...>(params, iter+1);
  }

#endif


  template <class Solution, typename Ret, typename Tuple, typename... Types, std::size_t... Is>
  std::enable_if_t<!std::is_void<Ret>::value> 
  ufunc_call(Ret (Solution::*fn)(Types...), 
             Tuple& params, 
             std::index_sequence<Is...>) {
    // ...

    Solution sol;
    Ret res = (sol.*fn)(std::get<Is>(params) ...);
    universal_print(res);
  }


  template <class Solution, typename Ret, typename Tuple, typename... Types, std::size_t... Is>
  std::enable_if_t<std::is_void<Ret>::value> 
  ufunc_call(Ret (Solution::*fn)(Types...), 
             Tuple& params, 
             std::index_sequence<Is...>) {
    // ...

    Solution sol;
    (sol.*fn)(std::get<Is>(params) ...);
    universal_print(std::get<0>(params));
  }


  template <class Solution, typename Ret, typename... Types>
  void ufunc(Ret (Solution::*fn)(Types...), std::string& line, double& exec_time) {
    // arguments to vector<string>
    std::vector<std::string> args = string_split(line);


#if __cplusplus >= 201703L
    std::tuple<std::__remove_cvref_t<Types> ...> params;
    input_gen(params, args.begin(), std::index_sequence_for<Types...>{});
#else
    // out-dated
    // typename tuple_type_gen<Types...>::type params;
    std::tuple<std::remove_const_t<std::remove_reference_t<Types> ...> params;
    input_gen(params, args.begin());
#endif

    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();

    ufunc_call(fn, params, std::index_sequence_for<Types...>{});

    std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    exec_time += elapsed.count();
  };

}

#endif // end of impl. of ufunc


using namespace std;


/**
 * @brief helper macro for reading lines from file
 * 
 * @param name string, file path
 * 
 * @exception plz use it in std namespace
 * 
 */
#define readlines(name) \
  ifstream f(name); \
  string line; \
  while (getline(f, line))


/**
 * @brief run method, all necessary work is done internally and implicitly
 * 
 * @param method class method, e.g. Solution::method_name
 * 
 * @deprecated generally replaced by UFUNC macro, for downward compatibility
 * 
 */
#define RUN(method) \
  string path = "Inputs/" + utils::to_txt_file(__FILE__);  \
  double exec_time = 0; \
  readlines(path) { \
    utils::run(&method, line, exec_time); \
  } \
  cout << "****** Execution time is: " << exec_time << " milliseconds. ******" << endl;


#if __cplusplus >= 201403L // start of UFUNC

/**
 * @brief updated version of RUN, code shrinks to 10% of the implementation of RUN with the help of variadic template and tuple
 * 
 * @param method class method, e.g. Solution::method_name
 * 
 */
#define UFUNC(method) \
  string path = "Inputs/" + utils::to_txt_file(__FILE__);  \
  double exec_time = 0; \
  readlines(path) { \
    utils::ufunc(&method, line, exec_time); \
  } \
  cout << "****** Execution time is: " << exec_time << " milliseconds. ******" << endl;

#else

#define UFUNC(method) RUN(method)

#endif // end of UFUNC


#endif // _UTILS_HPP
