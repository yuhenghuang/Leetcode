#include <local_leetcode.hpp>

class Solution {
  public:
    vector<int> preorderTraversal(TreeNode* root) {
      vector<int> res;

      stack<TreeNode*> s;

      while (root || !s.empty()) {
        for (; root; root = root->left) {
          s.push(root);
          res.push_back(root->val);
        }

        root = s.top()->right;
        s.pop();
      }

      return res;
    }
};


int main() {
  EXECS(Solution::preorderTraversal);
  return 0;
}