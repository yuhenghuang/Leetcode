#include <local_leetcode.hpp>

class Solution {
  public:
    TreeNode* invertTree(TreeNode* root) {
      if (root) {
        TreeNode* tmp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmp);
      }
      return root;
    }
};

int main() {
  EXECS(Solution::invertTree);
  return 0;
}
