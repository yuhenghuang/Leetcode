#include "utils.hpp"

class Solution {
  private:
    bool dfs(TreeNode* root, long l, long r) {
      if (!root)
        return true;

      return l<root->val && r>root->val &&
             dfs(root->left, l, root->val) && dfs(root->right, root->val, r);
    }

  public:
    bool isValidBST(TreeNode* root) {
      return dfs(root, LONG_MIN, LONG_MAX);
    }
};


int main() {
  UFUNC(Solution::isValidBST);
  return 0;
}