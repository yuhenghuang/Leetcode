#include "utils3.hpp"

class Solution {
  private:
    int dfs(TreeNode* root, vector<long>& prod) {
      if (!root)
        return 0;

      int l = dfs(root->left, prod);
      int r = dfs(root->right, prod);
      long p = (long) prod.size() - l - r - 1;

      prod[root->val] = (max(1L, p) * max(1, l)) * max(1, r);

      return l + r + 1;
    }

  public:
    int countHighestScoreNodes(vector<int>& parents) {
      int n = parents.size();

      TreeNode* root = new TreeNode[n];

      // val as node id
      root->val = 0;
      for (int i = 1; i < n; ++i) {
        root[i].val = i;

        TreeNode& parent = root[parents[i]];
        if (parent.left)
          parent.right = &root[i];
        else
          parent.left = &root[i];
      }

      // find product for each node
      vector<long> prod(n);
      dfs(root, prod);

      // count max products
      int res = 1;
      long p = -1; // current max product
      for (int i = 0; i < n; ++i)
        if (prod[i] > p) {
          p = prod[i];
          res = 1;
        }
        else if (prod[i] == p)
          ++res;

      // release memory
      delete[] root;

      return res;
    }
};


int main() {
  UFUNCS(Solution::countHighestScoreNodes);
  return 0;
}