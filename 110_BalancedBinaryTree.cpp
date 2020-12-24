#include "utils.hpp"

class Solution {
  private:
    int height(TreeNode* root) {
      if (!root)
        return 0;

      return 1 + max(height(root->left), height(root->right));
    }

  public:
    bool isBalanced(TreeNode* root) {
      if (!root)
        return true;
      
      return abs(height(root->left) - height(root->right)) < 2 && isBalanced(root->left) && isBalanced(root->right);
    }
};


int main() {
  UFUNC(Solution::isBalanced);
  return 0;
}