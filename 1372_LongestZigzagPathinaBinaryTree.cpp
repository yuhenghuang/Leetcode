#include <local_leetcode.hpp>

class Solution {
  private:
    typedef pair<int, int> pii_t;

    int res = 0;

    pii_t dfs(TreeNode* root) {
      if (!root)
        return pii_t{};

      int l = dfs(root->left).second + 1;
      int r = dfs(root->right).first + 1;

      res = max(res, max(l, r));

      return {l, r};
    }

  public:
    int longestZigZag(TreeNode* root) {
      res = 0;
      dfs(root);

      return res - 1;
    }
};


int main() {
  EXECS(Solution::longestZigZag);
  return 0;
}