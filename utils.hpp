#ifndef _UTILS_HPP
#define _UTILS_HPP


#include "DataStructure.h"

#include <sstream>
#include <iostream>
#include <iterator>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
#include <fstream>


namespace utils {

  template<typename T>
  T trans(const std::string& str) {
    return str;
  }

  template<>
  int trans(const std::string& str) {
    return stoi(str);
  }

  template<>
  char trans(const std::string& str) {
    return str[0];
  }

  template<>
  double trans(const std::string& str) {
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

      std::istringstream ss(line);
      std::vector<std::vector<T>> out;
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
  std::vector<std::string> string_split(std::string& str, char delim=';') {
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
    if (!head) return;
    std::cout << "[";
    while (head->next) {
      std::cout << head->val << ", ";
      head = head->next;
    }
    std::cout << head->val << "]" << std::endl;
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
    std::cout << "]";
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

}

#endif
