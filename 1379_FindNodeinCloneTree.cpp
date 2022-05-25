#include <local_leetcode.hpp>

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

    int getTargetCopy(TreeNode* original, TreeNode* cloned, int target) {
      return getTargetCopy(
        original,
        cloned,
        ll::find_node(original, target)
      )->val;
    }
};


int main() {
  EXECS(Solution::getTargetCopy, int, (TreeNode*, TreeNode*, int));
  return 0;
}