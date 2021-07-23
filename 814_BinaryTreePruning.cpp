#define PRINT_TREE_1D
#include "utils3.hpp"

class Solution {
  public:
    TreeNode* pruneTree(TreeNode* root) {
      if (!root)
        return nullptr;

      root->left = pruneTree(root->left);
      root->right = pruneTree(root->right);

      return (root->val == 1 || root->left || root->right) ? root : nullptr;
    }
};


int main() {
  UFUNCS(Solution::pruneTree);
  return 0;
}