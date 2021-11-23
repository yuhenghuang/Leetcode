#include "utils3.hpp"

class Solution {
  private:
    int res;

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

    int dfs2(TreeNode* node, int sum) {
      if (!node)
        return 0;

      sum = sum * 10 + node->val;
      
      return max(sum, dfs2(node->left, sum) + dfs2(node->right, sum));
    }

  public:
    int sumNumbers(TreeNode* root) {
      if (!root) return 0;
      res = 0;
      dfs(root, 0);
      return res;
    }

    int sumNumbersVer2(TreeNode* root) {
      return dfs2(root, 0);
    }
};


int main() {
  UFUNCS(Solution::sumNumbers);
  UFUNCS(Solution::sumNumbersVer2);
  return 0;
}