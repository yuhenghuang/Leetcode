#include "DataStructure.h"
#include <cmath>

class Solution {
  public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
      TreeNode* x = root;
      TreeNode* y = nullptr;
      while (x) {
        y = x;
        if (x->val > val)
          x = x->left;
        else
          x = x->right;
      }
      TreeNode* p = new TreeNode(val);

      if (!y)
        root = p;
      else if (y->val > val)
        y->left = p;
      else
        y->right = p;
      return root;
    }
};