#ifndef UTILS_HPP
#define UTILS_HPP

#include <sstream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
#include "DataStructure.h"


namespace utils {

  template<typename T>
  T trans(const std::string& str) {
    return stoi(str);
  }

  template<>
  std::string trans(const std::string& str) {
    return str;
  }

  /**
   * @brief Parse string to 1D vector, e.g. "[3,2,7]", white spaces allowed.
   * 
   * @tparam T typename, current support int, std::string
   * 
   */
  template<typename T>
  struct parse_vector_1d {
    std::vector<T> operator()(std::string& row) {
      std::vector<T> out;
      row = regex_replace(row, std::regex("[\\[\\]\\s]+"), "");
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
   * @tparam T typename, current support int, std::string
   * 
   */
  template<typename T>
  struct parse_vector_2d {
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
   * @param row Serialized string of a tree, e.g. "[1, NULL, 2]" white space allowed.
   * @return TreeNode* root
   */
  TreeNode *parse_tree(std::string& row) {
    TreeNode* root = nullptr;
    TreeNode* node;
    std::queue<TreeNode*> q;

    row = regex_replace(row, std::regex("[\\[\\]\\s]+"), "");
    std::istringstream ss(row);
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
}

#endif