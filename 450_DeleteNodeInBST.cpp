#include "utils3.hpp"

class Solution {
  public:
    TreeNode* deleteNode(TreeNode* root, int key) {
      if (!root) return nullptr;
      if (root->val > key) 
        root->left = deleteNode(root->left, key);
      else if (root->val < key) 
        root->right = deleteNode(root->right, key);
      else {
        // two children
        if (root->left && root->right) {
          // find the leftmost node of right child
          // which is the node larger than root
          TreeNode* tmp = root->right;
          while (tmp->left)
            tmp = tmp->left;

          // replace root by that node
          // and try delete that node which has only one child
          root->val = tmp->val;
          root->right = deleteNode(root->right, tmp->val);
        }
        // one or zero child
        else 
          root = root->left ? root->left : root->right;
      }
      return root;
    }
};


int main() {
  UFUNCS(Solution::deleteNode);
  return 0;
}