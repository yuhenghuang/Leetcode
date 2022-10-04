#include <local_leetcode.hpp>

class Solution {
  public:
    bool hasPathSum(TreeNode* root, int targetSum) {
      stack<pair<TreeNode*, int>> s;

      if (root)
        s.emplace(root, 0);

      while (!s.empty()) {
        auto [root, sum] = s.top();
        s.pop();

        sum += root->val;

        if (!root->left && !root->right) {
          if (sum == targetSum)
            return true;
        }
        else {
          if (root->left)
            s.emplace(root->left, sum);

          if (root->right)
            s.emplace(root->right, sum);
        }
      }

      return false;
    }
};


int main() {
  EXECS(Solution::hasPathSum);
  return 0;
}