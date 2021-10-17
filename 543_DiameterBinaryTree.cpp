#include "utils3.hpp"

class Solution {
  private:
    int res;

    int dfs(TreeNode* root) {
      if (!root)
        return 0;

      int l = dfs(root->left);
      int r = dfs(root->right);

      if (l + r > res)
        res = l + r;

      return 1 + max(l, r);
    }

  public:
    int diameterOfBinaryTree(TreeNode* root) {
      res = 0;

      dfs(root);

      return res;
    }
};


int main() {
  UFUNCS(Solution::diameterOfBinaryTree);
  return 0;
}