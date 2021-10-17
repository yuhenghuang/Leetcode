#define _DELETE_RETURN_POINTER
#include "utils3.hpp"

class Solution {
  private:
    TreeNode* dfs(int i, int j, vector<int>& preorder) {
      if (i>j) return nullptr;
      TreeNode* root = new TreeNode(preorder[i]);
      if (i==j) return root;
      int k=i+1;
      while (k<=j && preorder[k] < preorder[i])
        ++k;

      root->left = dfs(i+1, k-1, preorder);
      root->right = dfs(k, j, preorder);
      return root;
    }

  public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
      return dfs(0, preorder.size()-1, preorder);
    }
};


int main() {
  UFUNCS(Solution::bstFromPreorder);
  return 0;
}
