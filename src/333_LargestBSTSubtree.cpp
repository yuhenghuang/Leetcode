#include "utils3.hpp"

class Solution {
  private:
    int dfs(TreeNode* root, int lbound, int rbound, int& res) {
      if (!root)
        return 0;
      else if (root->val <= lbound || root->val >= rbound)
        return -1;

      int l = dfs(root->left, lbound, root->val, res);
      int r = dfs(root->right, root->val, rbound, res);

      if (l < 0 || r < 0)
        return -1;
      else {
        // count of nodes in bst subtree
        int count = 1 + l + r;

        if (count > res)
          res = count;

        return count;
      }
    }

  public:
    int largestBSTSubtree(TreeNode* root) {
      int res = 0;
      dfs(root, INT_MIN, INT_MAX, res);

      return res;
    }
};


int main() {
  UFUNCS(Solution::largestBSTSubtree);
  return 0;
}