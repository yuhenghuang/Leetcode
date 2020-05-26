#include "DataStructure.h"

class Solution {
  public:
    TreeNode* deleteNode(TreeNode* root, int key) {
      if (!root) return nullptr;
      if (root->val > key) 
        root->left = deleteNode(root->left, key);
      else if (root->val < key) 
        root->right = deleteNode(root->right, key);
      else {
        if (!root->left && !root->right)
          return nullptr;
        else if (!root->left)
          return root->right;
        else if (!root->right)
          return root->left;
        else {
          TreeNode* tmp = root->right;
          while (tmp->left)
            tmp = tmp->left;
          root->val = tmp->val;
          root->right = deleteNode(root->right, tmp->val);
        }
      }
      return root;
    }
};