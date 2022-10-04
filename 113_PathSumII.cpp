#include <local_leetcode.hpp>

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

    vector<vector<int>> pathSumNew(TreeNode* root, int targetSum) {
      int sum = 0;
      vector<int> path;
      vector<vector<int>> res;

      unordered_set<TreeNode*> seen;
      stack<TreeNode*> s;
      while (!s.empty() || root) {
        while (root) {
          s.push(root);
          path.push_back(root->val);
          sum += root->val;

          root = root->left;
        }

        root = s.top();

        if (root->right && seen.count(root) == 0) {
          seen.insert(root);
          root = root->right;
        }
        else {
          if (sum == targetSum && root->left == nullptr && root->right == nullptr)
            res.push_back(path);

          s.pop();
          path.pop_back();
          sum -= root->val;

          root = nullptr;          
        }
      }

      return res;
    }
};


int main() {
  EXECS(Solution::pathSum);
  EXECS(Solution::pathSumNew);
  return 0;
}
