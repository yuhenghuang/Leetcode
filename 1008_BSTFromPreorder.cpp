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

    TreeNode* dfs(int*& i, int* j, int rbound) {
      if (i == j)
        return nullptr;

      TreeNode* root = new TreeNode(*i++);

      if (i != j && *i < root->val)
        root->left = dfs(i, j, root->val);

      if (i != j && *i < rbound)
        root->right = dfs(i, j, rbound);

      return root;
    }

  public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
      return dfs(0, preorder.size()-1, preorder);
    }

    TreeNode* bstFromPreorderOn(vector<int>& preorder) {
      int* i = preorder.data();
      return dfs(i, i + preorder.size(), INT_MAX);
    }
};


int main() {
  UFUNCS(Solution::bstFromPreorder);
  UFUNCS(Solution::bstFromPreorderOn);
  return 0;
}
