#include <local_leetcode.hpp>

class Solution {
  public:
    int sumEvenGrandparent(TreeNode* root) {
      // node, is even parent?
      queue<pair<TreeNode*, bool>> q;
      
      if (root)
        q.emplace(root, false);

      int res = 0;
      while (!q.empty()) {
        int n = q.size();
        while (n--) {
          auto [root, flag] = q.front();
          q.pop();

          if (root->left) {
            if (flag)
              res += root->left->val;

            q.emplace(root->left, (root->val & 1) == 0);
          }

          if (root->right) {
            if (flag)
              res += root->right->val;

            q.emplace(root->right, (root->val & 1) == 0);
          }
        }
      }

      return res;
    }
};


int main() {
  EXECS(Solution::sumEvenGrandparent);
  return 0;
}