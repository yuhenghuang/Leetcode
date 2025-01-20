#include <local_leetcode.hpp>

class Solution {
  private:
    void dfs(TreeNode* root, vector<int>& vals) {
      if (!root)
        return;
      else if (!root->left && !root->right) {
        vals.push_back(root->val);
        return;
      }

      dfs(root->left, vals);
      dfs(root->right, vals);
    }

  public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
      vector<int> vals1, vals2;

      dfs(root1, vals1);
      dfs(root2, vals2);

      return vals1 == vals2;
    }
};


int main() {
  EXECS(Solution::leafSimilar);
  return 0;
}