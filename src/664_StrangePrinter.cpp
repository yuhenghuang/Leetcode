#include <local_leetcode.hpp>

class Solution {
  public:
    int strangePrinter(string _s) {
      string s;
      s.push_back(_s.front());

      for (int i = 1; i < _s.size(); ++i)
        if (s.back() != _s[i])
          s.push_back(_s[i]);

      const int n = s.size();

      int dp[n+1][n];

      for (int i = 0; i < n; ++i) 
        dp[i+1][i] = 0;

      for (int i = n - 1; i >= 0; --i)
        for (int j = i; j < n; ++j) {
          int res = 1 + dp[i+1][j];

          for (int k = i + 1; k <= j; ++k)
            if (s[i] == s[k])
              res = min(res, dp[i][k-1] + dp[k+1][j]);

          dp[i][j] = res;
        }

      return dp[0][n-1];
    }
};


int main() {
  EXECS(Solution::strangePrinter);
  return 0;
}