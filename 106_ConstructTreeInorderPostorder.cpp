#define _LL_DELETE_RETURN_POINTER
#include <local_leetcode.hpp>

class Solution {
  public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      if (inorder.size()==0) return nullptr;
      return dfs(0, 0, inorder.size()-1, inorder, postorder);
    }

    TreeNode* dfs(int i, int j, int k, vector<int>& inorder, vector<int>& postorder) {
      if (k<0) return nullptr;
      if (k==0) return new TreeNode(inorder[i]);
      TreeNode* root = new TreeNode(postorder[j+k]);
      int l = 0;
      while (inorder[i+l]!=root->val)
        ++l;
      root->left = dfs(i, j, l-1, inorder, postorder);
      root->right = dfs(i+l+1, j+l, k-l-1, inorder, postorder);
      return root;
    }
};

int main(){
  /*
  vector<int> in = {3, 2, 1};
  Solution sol;
  TreeNode* root = sol.buildTree(in, in);
  */

  EXECS(Solution::buildTree);
  return 0;
}