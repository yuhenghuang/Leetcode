#include "DataStructure.h"

class Solution {
  private:
    int res;
  public:
    int sumNumbers(TreeNode* root) {
      if (!root) return 0;
      res = 0;
      dfs(root, 0);
      return res;
    }

    void dfs(TreeNode* node, int acc) {
      acc = acc * 10 + node->val;
      if (!node->left && !node->right) {
        res += acc;
        return;
      }
      if (node->left) 
        dfs(node->left, acc);
      if (node->right) {
        dfs(node->right, acc);
      }
    }
};