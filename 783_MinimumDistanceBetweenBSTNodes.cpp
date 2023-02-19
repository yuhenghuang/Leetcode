#include <local_leetcode.hpp>

class Solution {
  public:
    int minDiffInBST(TreeNode* root) {
      stack<TreeNode*> s;

      int prev = INT_MIN + 1e6;
      int res = INT_MAX;

      while (!s.empty() || root) {
        while (root) {
          s.push(root);
          root = root->left;
        }

        root = s.top();
        s.pop();

        if (root->val - prev < res)
          res = root->val - prev;

        prev = root->val;
        root = root->right;
      }

      return res;
    }

    int minDiffInBSTO1(TreeNode* root) {
      int left = INT_MIN + 1e6;
      int res = INT_MAX;

      while (root) {
        if (root->left == nullptr) {
          if (root->val - left < res)
            res = root->val - left;

          left = root->val;
          root = root->right;
        }
        else {
          TreeNode* pre = root->left;
          while (pre->right && pre->right != root)
            pre = pre->right;

          if (pre->right == nullptr) {
            pre->right = root;
            root = root->left;
          }
          else {
            if (root->val - left < res)
              res = root->val - left;

            left = root->val;

            root = root->right;
            pre->right = nullptr;
          }
        }
      }

      return res;
    }
};


int main() {
  EXECS(Solution::minDiffInBST);
  EXECS(Solution::minDiffInBSTO1);
  return 0;
}