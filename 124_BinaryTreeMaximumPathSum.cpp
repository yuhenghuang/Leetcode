#include <local_leetcode.hpp>

class Solution {
  private:
    int res;

    int dfs(TreeNode* root) {
      if (!root)
        return 0;

      int left = dfs(root->left);
      int right = dfs(root->right);

      res = max(res, root->val + left + right);

      return max(0, max(root->val + left, root->val + right));
    }

  public:
    int maxPathSum(TreeNode* root) {
      res = INT_MIN;

      dfs(root);

      return res;
    }
};


int main() {
  EXECS(Solution::maxPathSum);
  return 0;
}