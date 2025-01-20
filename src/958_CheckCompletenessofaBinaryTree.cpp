#include <local_leetcode.hpp>

class Solution {
  private:
    typedef pair<int, int> ii_t;

    ii_t dfs(TreeNode* root, int i) {
      if (!root)
        return {0, 0};

      ii_t&& p = dfs(root->left, i * 2);
      ii_t&& q = dfs(root->right, i * 2 + 1);

      return {1 + p.first + q.first, max(i, max(p.second, q.second))};
    }

  public:
    bool isCompleteTreeDfs(TreeNode* root) {
      // integer overflow
      ii_t&& p = dfs(root, 1);
      return p.first == p.second;
    }

    bool isCompleteTree(TreeNode* root) {
      queue<pair<TreeNode*, int>> q;

      if (root)
        q.emplace(root, 1);

      int size = 0;
      while (!q.empty()) {
        auto [root, i] = q.front();
        q.pop();

        if (++size < i)
          return false;

        if (root->left)
          q.emplace(root->left, i * 2);

        if (root->right)
          q.emplace(root->right, i * 2 + 1);
      }

      return true;
    }
};


int main() {
  EXECS(Solution::isCompleteTree);
  return 0;
}