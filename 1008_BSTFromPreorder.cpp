#include "DataStructure.h"
#include <vector>
using namespace std;

class Solution {
  public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
      return dfs(0, preorder.size()-1, preorder);
    }

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
};