#include "utils2.hpp"

class Solution {
  private:
    bool comp(const string& x, const string& y) const {
      int i = x.size() - 1;
      int j = y.size() - 1;
      while (i>=0 && j>=0) {
        if (x[i] < y[j])
          return true;
        else if (x[i] > y[j])
          return false;

        --i; --j;
      }

      return i < 0;
    }

    void dfs(TreeNode* root, string& s, string& res) {
      s.push_back((char)('a'+root->val));

      if (!root->left && !root->right) {
        if (comp(s, res))
          res = s;
      }


      if (root->left)
        dfs(root->left, s, res);

      if (root->right)
        dfs(root->right, s, res);

      s.pop_back();
    }

  public:
    string smallestFromLeaf(TreeNode* root) {
      string res;
      if (!root)
        return res;
      
      res += (char)('z' + 1);
      string s;
      dfs(root, s, res);

      reverse(res.begin(), res.end());
      return res;
    }
};


int main() {
  UFUNC(Solution::smallestFromLeaf);
  return 0;
}