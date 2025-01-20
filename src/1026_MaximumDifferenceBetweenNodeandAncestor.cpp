#include <local_leetcode.hpp>

class Solution {
  private:
    int dfs(TreeNode* root, const int& ancestor) {
      if (!root) return 0;
      return max(abs(root->val - ancestor), max(dfs(root->left, ancestor), dfs(root->right, ancestor)));
    }

    int dfs(TreeNode* root, int curMin, int curMax) {
      if (!root) return curMax - curMin;

      curMax = max(root->val, curMax);
      curMin = min(root->val, curMin);
      return max(dfs(root->left, curMin, curMax), dfs(root->right, curMin, curMax));
    }
  public:
    int maxAncestorDiff(TreeNode* root) {
      if (!root) return 0;

      return max(dfs(root, root->val), max(maxAncestorDiff(root->left), maxAncestorDiff(root->right)));
    }

    int maxAncestorDiffOn(TreeNode* root) {
      return dfs(root, root->val, root->val);
    }
};


int main() {
  EXECS(Solution::maxAncestorDiff);
  EXECS(Solution::maxAncestorDiffOn);
  return 0;
}