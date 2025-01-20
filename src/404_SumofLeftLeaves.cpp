#include "utils3.hpp"

class Solution {
  private:
    int dfs(TreeNode* root, bool left) {
      if (!root) return 0;
      if (!root->left && !root->right)
        return left ? root->val : 0;
      return dfs(root->left, true) + dfs(root->right, false);
    }

  public:
    int sumOfLeftLeaves(TreeNode* root) {
      if (!root) return 0;
      return dfs(root->left, true) + dfs(root->right, false);
    }
};

int main() {
  UFUNCS(Solution::sumOfLeftLeaves);
  return 0;
}