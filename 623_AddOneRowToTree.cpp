#define PRINT_TREE_1D
#include "utils2.hpp"

class Solution {
  private:
    void recurse(TreeNode* root, int v, int d) {
      if (!root)
        return;
      
      if (d==2) {
        root->left = new TreeNode(v, root->left, nullptr);
        root->right = new TreeNode(v, nullptr, root->right);
        return;
      }
      
      recurse(root->left, v, d-1);
      recurse(root->right, v, d-1);
    }
  
  public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
      if (d==1) 
        return new TreeNode(v, root, nullptr);
      
      recurse(root, v, d);
      return root;
    }
};


int main() {
  UFUNC(Solution::addOneRow);
  return 0;
}