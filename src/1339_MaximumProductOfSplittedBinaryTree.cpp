#include <unordered_map>
#include "utils3.hpp"

class Solution {
  private:
    int sumSubtree(TreeNode* root, unordered_map<TreeNode*, int>& m) {
      if (!root)
        return 0;

      return m[root] = root->val + sumSubtree(root->left, m) + sumSubtree(root->right, m);
    }

    long findMaxProduct(TreeNode* root, unordered_map<TreeNode*, int>& m, long total) {
      if (!root)
        return 0;

      return max(
        max(
          m[root->left] * (total - m[root->left]), 
          m[root->right] * (total - m[root->right])
        ),
        max(
          findMaxProduct(root->left, m, total), 
          findMaxProduct(root->right, m, total)
        )
      );
    }

  public:
    int maxProduct(TreeNode* root) {
      unordered_map<TreeNode*, int> m;
      return findMaxProduct(
        root,
        m,
        sumSubtree(root, m)
      ) % long(1e9 + 7);
    }
};


int main() {
  UFUNCS(Solution::maxProduct);
  return 0;
}