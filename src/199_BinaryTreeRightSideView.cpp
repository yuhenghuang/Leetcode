#include "utils2.hpp"

class Solution {
  public:
    vector<int> rightSideView(TreeNode* root) {
      queue<TreeNode*> q;

      if (root)
        q.push(root);

      vector<int> res;
      while (!q.empty()) {
        res.push_back(q.front()->val);
        int n = q.size();
        while (n--) {
          root = q.front(); q.pop();

          if (root->right)
            q.push(root->right);
          if (root->left)
            q.push(root->left);
        }
      }

      return res;
    }
};


int main() {
  UFUNC(Solution::rightSideView);
  return 0;
}