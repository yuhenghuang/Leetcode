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

    TreeNode* buildTreeLambda(vector<int>& inorder, vector<int>& postorder) {
      function<TreeNode* (int, int, int)> build = [&inorder, &postorder, &build] (int start1, int start2, int length) -> TreeNode* {
        if (length <= 0)
          return nullptr;

        int i = 0;
        int val = postorder[start2 + length - 1];
        for (; inorder[start1 + i] != val; ++i);

        return new TreeNode(
          val,
          build(start1, start2, i),
          build(start1 + i + 1, start2 + i, length - i - 1)
        );
      };

      return build(0, 0, inorder.size());
    }
};

int main(){
  /*
  vector<int> in = {3, 2, 1};
  Solution sol;
  TreeNode* root = sol.buildTree(in, in);
  */

  EXECS(Solution::buildTree);
  EXECS(Solution::buildTreeLambda);
  return 0;
}