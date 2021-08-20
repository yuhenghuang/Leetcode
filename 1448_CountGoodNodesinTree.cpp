#include "utils3.hpp"

class Solution {
  private:
    int goodNodes(TreeNode* root, int val) {
      if (!root)
        return 0;
      else if (root->val < val)
        return goodNodes(root->left, val) + goodNodes(root->right, val);
      else
        return 1 + goodNodes(root->left, root->val) + goodNodes(root->right, root->val);
    }

  public:
    int goodNodes(TreeNode* root) {
      return goodNodes(root, INT_MIN);
    }
};


int main() {
  UFUNCS(Solution::goodNodes, int, (TreeNode*));
  return 0;
}
