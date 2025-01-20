#include <local_leetcode.hpp>

class Solution {
  private:
    typedef pair<int, int> ii_t;

    ii_t dfs(TreeNode* root, ii_t p, const int s) {
      if (!root)
        return p;

      // increment height
      ++p.first;

      if (root->val == s)
        p.second = p.first;

      auto&& p1 = dfs(root->left, p, s);
      auto&& p2 = dfs(root->right, p, s);

      return {max(p1.first, p2.first), max(p1.second, p2.second)};
    }

    void dfs(TreeNode* root, vector<TreeNode*>& s, const int start, vector<TreeNode*>& path) {
      if (!root)
        return;

      s.push_back(root);

      if (root->val == start)
        path = s;

      dfs(root->left, s, start, path);
      dfs(root->right, s, start, path);

      s.pop_back();
    }

    int dfs(TreeNode* root, int h = 0) {
      if (!root)
        return h;

      return max(dfs(root->left, h + 1), dfs(root->right, h + 1));
    }

  public:
    int amountOfTimeWrong(TreeNode* root, int start) {
      //wrong answer

      ii_t p = dfs(root->left, {0, 0}, start);
      ii_t q = dfs(root->right, {0, 0}, start);

      // as if start is always found on left half
      if (q.second > 0)
        swap(p, q);

      return max(p.first - p.second, q.first + p.second);
    }

    int amountOfTime(TreeNode* root, int start) {
      vector<TreeNode*> path;
      vector<TreeNode*> s;

      dfs(root, s, start, path);

      const int n = path.size();

      int res = max(dfs(path.back()->left), dfs(path.back()->right));
      for (int i = n - 2; i >= 0; --i) {
        res = max(
          res,
          n - 1 - i + dfs(path[i]->left != path[i+1] ? path[i]->left : path[i]->right)
        );
      }

      return res;
    }
};


int main() {
  EXECS(Solution::amountOfTime);
  return 0;
}