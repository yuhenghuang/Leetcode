#include <local_leetcode.hpp>

class Solution {
  private:
    typedef pair<int, int> ll_t;

    int res;

    ll_t dfs(TreeNode* root) {
      if (!root)
        return ll_t();

      ll_t out(root->val, 1);

      ll_t&& left = dfs(root->left);
      ll_t&& right = dfs(root->right);

      out.first += left.first + right.first;
      out.second += left.second + right.second;

      if (out.first / out.second == root->val)
        ++res;

      return out;
    }

  public:
    int averageOfSubtree(TreeNode* root) {
      res = 0;

      dfs(root);

      return res;
    }
};


int main() {
  EXECS(Solution::averageOfSubtree);
  return 0;
}