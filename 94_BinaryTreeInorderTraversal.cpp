#include <local_leetcode.hpp>

class Solution {
  public:
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> res;

      stack<TreeNode*> s;
      while (root || !s.empty()) {
        while (root) {
          s.push(root);
          root = root->left;
        }

        root = s.top();
        s.pop();

        res.push_back(root->val);
        root = root->right;
      }

      return res;
    }

    vector<int> inorderTraversalO1(TreeNode* root) {
      vector<int> res;

      while (root) {
        if (root->left == nullptr) {
          res.push_back(root->val);
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
            pre->right = nullptr;
            res.push_back(root->val);
            root = root->right;
          }
        }
      }

      return res;
    }
};


int main() {
  EXECS(Solution::inorderTraversal);
  EXECS(Solution::inorderTraversalO1);
  return 0;
}
