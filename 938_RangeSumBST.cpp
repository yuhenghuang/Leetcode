#include "utils.hpp"

class Solution {
  public:
    int rangeSumBST(TreeNode* root, const int& low, const int& high) {
      if (!root) return 0;
      else if (root->val<low)
        return rangeSumBST(root->right, low, high);
      else if (root->val>high)
        return rangeSumBST(root->left, low, high);
      else
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};


int main() {
  UFUNC(Solution::rangeSumBST);
  return 0;
}