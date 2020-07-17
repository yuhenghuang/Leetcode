#include "DataStructure.h"

class Solution {
  public:
    int sumOfLeftLeaves(TreeNode* root) {
      if (!root) return 0;
      return sumOfLeafLeaves(root->left, true) + sumOfLeafLeaves(root->right, false);
    }

    int sumOfLeafLeaves(TreeNode* root, bool left) {
      if (!root) return 0;
      if (!root->left && !root->right)
        return left ? root->val : 0;
      return sumOfLeafLeaves(root->left, true) + sumOfLeafLeaves(root->right, false);
    }
};

int main() {
  Solution sol;
  return 0;
}