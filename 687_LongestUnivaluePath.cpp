#include <local_leetcode.hpp>

class Solution {
  private:
    int res = 0;

    int dfs(TreeNode* root) {
      if (!root)
        return 0;

      int l = dfs(root->left) + 1;
      int r = dfs(root->right) + 1;

      if (!root->left || root->val != root->left->val)
        l = 0;

      if (!root->right || root->val != root->right->val)
        r = 0;

      res = max(res, l + r);

      return max(l, r);
    }

  public:
    int longestUnivaluePath(TreeNode* root) {
      res = 0;
      dfs(root);
      return res;
    }
};


int main() {
  EXECS(Solution::longestUnivaluePath);
  return 0;
}