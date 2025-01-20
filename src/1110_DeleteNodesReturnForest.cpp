/*
#include "DataStructure.h"
#include <vector>
using namespace std;
*/

#define _LL_NONTRIVIAL_SOLUTION_CTOR
#define _LL_FLATTEN_2D
#include <local_leetcode.hpp>

class Solution {
  private:
    vector<TreeNode*> res;
    vector<bool> todo;
  public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
      res.clear();
      todo.assign(1001, false);
      
      for (int& idx : to_delete)
        todo[idx] = true;
      if (!todo[root->val])
        res.push_back(root);
      dfs(root);
      return res;
    }

    void dfs(TreeNode* node) {
      if (!node) return;
      
      dfs(node->left);
      dfs(node->right);
      if (todo[node->val]) {
        if (node->left && !todo[node->left->val]) 
          res.push_back(node->left);
        if (node->right && !todo[node->right->val])
          res.push_back(node->right); 
      }
      else {
        if (node->left && todo[node->left->val])
          node->left = nullptr;
        if (node->right && todo[node->right->val])
          node->right = nullptr;
      }
    }
};


int main() {
  EXECS(Solution::delNodes);
  return 0;
}