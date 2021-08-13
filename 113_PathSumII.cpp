#include "utils3.hpp"

class Solution {
  private:
    void dfs(TreeNode* root, int t, vector<int>& s, vector<vector<int>>& res) {
      if (!root)
        return;

      s.push_back(root->val);
      t -= root->val;

      if (t == 0 && !root->left && !root->right)
        res.push_back(s);
      else {
        dfs(root->left, t, s, res);
        dfs(root->right, t, s, res);
      }

      s.pop_back();
    }

  public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
      vector<int> s;
      vector<vector<int>> res;

      dfs(root, targetSum, s, res);
      return res;
    }
};


int main() {
  UFUNCS(Solution::pathSum);
  return 0;
}