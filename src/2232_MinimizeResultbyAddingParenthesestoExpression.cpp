#include <local_leetcode.hpp>

class Solution {
  public:
    string minimizeResult(string expression) {
      int n = expression.size();
      int m = expression.find('+');

      // outside of parenthesis, inside of parenthesis
      vector<pair<int, int>> lhs, rhs;

      lhs.emplace_back(1, stoi(expression.substr(0, m)));
      for (int i = 1; i < m; ++i)
        lhs.emplace_back(stoi(expression.substr(0, i)), stoi(expression.substr(i, m)));

      for (int i = m + 2; i < n; ++i)
        rhs.emplace_back(stoi(expression.substr(i, n - i)), stoi(expression.substr(m + 1, i - m - 1)));

      rhs.emplace_back(1, stoi(expression.substr(m+1, n - m - 1)));

      int res = INT_MAX;

      int p, q;

      for (int i = 0; i < m; ++i)
        for (int j = m + 1; j < n; ++j) {
          int temp = lhs[i].first * rhs[j-m-1].first * (lhs[i].second + rhs[j-m-1].second);

          if (temp < res) {
            p = i;
            q = j;

            res = temp;
          }
        }

      string ans = expression;

      ans.insert(q + 1, 1, ')');
      ans.insert(p, 1, '(');

      return ans;
    }
};


int main() {
  EXECS(Solution::minimizeResult);
  return 0;
}