#include "DataStructure.h"

class Solution {
  public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
      if (!original) return nullptr;
      else if (original==target) return cloned;
      else {
        TreeNode* temp = getTargetCopy(original->left, cloned->left, target);
        return temp ? temp : getTargetCopy(original->right, cloned->right, target);
      }
    }
};