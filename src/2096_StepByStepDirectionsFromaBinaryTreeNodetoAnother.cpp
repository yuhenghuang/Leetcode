#include <local_leetcode.hpp>

class Solution {
  private:
    void dfs(TreeNode* root, int s, int d, string& start, string& dest, string& str) {
      if (!root)
        return;

      if (root->val == s)
        start = str;
      else if (root->val == d)
        dest = str;

      str.push_back('L');
      dfs(root->left, s, d, start, dest, str);
      str.pop_back();

      str.push_back('R');
      dfs(root->right, s, d, start, dest, str);
      str.pop_back();
    }

  public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
      string start;
      string dest;
      string str;
      dfs(root, startValue, destValue, start, dest, str);

      int m = start.size();
      int n = dest.size();

      int i = 0;
      int j = 0;
      for (;i < m && j < n && start[i] == dest[j]; ++i, ++j);

      return string(m - i, 'U') + dest.substr(j, n - j);
    }
};


int main() {
  EXECS(Solution::getDirections);
  return 0;
}