#include "utils2.hpp"

class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode* root) {
      queue<TreeNode*> q;

      if (root) q.push(root);

      vector<vector<int>> res;
      while (!q.empty()) {
        vector<int>& level = res.emplace_back();
        int n = q.size();
        while (n--) {
          root = q.front();
          q.pop();

          level.push_back(root->val);
          if (root->left) q.push(root->left);
          if (root->right) q.push(root->right);
        }
      }

      return res;
    }
};


int main() {
  UFUNC(Solution::levelOrder);
  return 0;
}