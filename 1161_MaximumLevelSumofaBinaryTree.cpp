#include <local_leetcode.hpp>

class Solution {
  public:
    int maxLevelSum(TreeNode* root) {
      vector<int> levelSum;

      function<void (TreeNode*, size_t)> dfs = [&levelSum, &dfs] (TreeNode* root, size_t level) -> void {
        if (!root)
          return;

        if (levelSum.size() == level)
          levelSum.push_back(0);

        levelSum[level] += root->val;

        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
      };

      dfs(root, 0);

      int res = 0;
      int sum = INT_MIN;

      for (int i = 0; i < (int) levelSum.size(); ++i)
        if (levelSum[i] > sum) {
          sum = levelSum[i];
          res = i + 1;
        }

      return res;
    }
};


int main() {
  EXECS(Solution::maxLevelSum);
  return 0;
}