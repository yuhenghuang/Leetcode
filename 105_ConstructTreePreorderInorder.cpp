#include "utils2.hpp"

class Solution {
  private:
    TreeNode* buildTreeImpl(int i, int j, int k, vector<int>& preorder, vector<int>& inorder) {
      if (k < 1)
        return nullptr;

      int val = preorder[i];
      TreeNode* root = new TreeNode(val);

      // may use hash table to optimize this block
      int l = 0;
      for (; l < k; ++l)
        if (inorder[j + l] == val)
          break;

      root->left = buildTreeImpl(i + 1, j, l, preorder, inorder);
      root->right = buildTreeImpl(i + 1 + l, j + 1 + l, k - l - 1, preorder, inorder);

      return root;
    }

  public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      return buildTreeImpl(0, 0, preorder.size(), preorder, inorder);
    }
};


int main() {
  UFUNC(Solution::buildTree);
  return 0;
}