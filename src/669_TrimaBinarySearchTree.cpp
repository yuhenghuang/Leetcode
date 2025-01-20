#include <local_leetcode.hpp>

class Solution {
  public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
      if (!root) return nullptr;

      if (low <= root->val && root->val <= high) {
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        return root;
      }
      else {
        TreeNode* l = trimBST(root->left, low, high);
        TreeNode* r = trimBST(root->right, low, high);
        if (!l)
          return r;
        else if (!r)
          return l;
        else {
          // neven needed ...
          root = l;
          while (l->right)
            l = l->right;
          
          l->right = r;
          return root;
        }
      }
    }
};


int main() {
  EXECS(Solution::trimBST);
  return 0;
}