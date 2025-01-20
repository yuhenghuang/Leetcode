#include <local_leetcode.hpp>

static int arr = [](){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();

class Solution {
  public:
    int kthSmallestOld(TreeNode* root, int k) {
      stack<TreeNode*> s;
      while (!s.empty() || root) {
        while (root) {
          s.push(root);
          root = root->left;
        }

        do {
          --k;
          if (k==0)
            return s.top()->val;
          root = s.top();
          s.pop();
        } while (!s.empty() && !root->right);

        root = root->right;
      }
      return -1;
    }

    int kthSmallest(TreeNode* root, int k) {
      stack<TreeNode*> s;
      while (root || !s.empty()) {
        while (root) {
          s.push(root);
          root = root->left;
        }

        root = s.top();
        s.pop();

        if (--k == 0)
          return root->val;

        root = root->right;
      }

      return -1;
    }
};


int main() {
  EXECS(Solution::kthSmallestOld);
  EXECS(Solution::kthSmallest);
  return 0;
}