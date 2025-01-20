#include <local_leetcode.hpp>

class Solution {
  private:
    bool isMirror(TreeNode* root1, TreeNode* root2) {
      if (root1 == nullptr && root2 == nullptr)
        return true;
      else if (root1 == nullptr || root2 == nullptr || root1->val != root2->val)
        return false;

      return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
    }

  public:
    bool isSymmetric(TreeNode* root) {
      return isMirror(root, root);
    }
};


int main() {
  EXECS(Solution::isSymmetric);
  return 0;
}