#include <local_leetcode.hpp>

class Solution {
  private:
    bool dfs(TreeNode* root, int64_t l, int64_t r) {
      if (!root)
        return true;

      return l < root->val && \
             r > root->val && \
             dfs(root->left, l, root->val) && \
             dfs(root->right, root->val, r);
    }

  public:
    bool isValidBST(TreeNode* root) {
      return dfs(root, INT64_MIN, INT64_MAX);
    }
};


int main() {
  EXECS(Solution::isValidBST);
  return 0;
}
