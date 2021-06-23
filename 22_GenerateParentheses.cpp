#include "utils2.hpp"

class Solution {
  private:
    void dfs(int i, int l, int n, string& s, vector<string>& res) {
      if (i == (n << 1)) {
        if (l == 0)
          res.push_back(s);

        return;
      }

      if (l > 0) {
        s.push_back(')');
        dfs(i+1, l-1, n, s, res);
        s.pop_back();
      }

      if (l < n) {
        s.push_back('(');
        dfs(i+1, l+1, n, s, res);
        s.pop_back();
      }
    }

  public:
    vector<string> generateParenthesis(int n) {
      vector<string> res;

      string s;
      dfs(0, 0, n, s, res);

      return res;
    }
};


int main() {
  UFUNC(Solution::generateParenthesis);
  return 0;
}