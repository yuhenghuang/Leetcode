#include <local_leetcode.hpp>

class Solution {
  public:
    int minInsertions(string s) {
      int n = s.size();

      if (n < 2)
        return 0;

      // [0, i) , [j, n)
      uint16_t dp[501][501];
      // memset(dp, 0, sizeof(dp[501]) * (n + 1));

      // empty right substring case
      for (int i = 1; i <= n; ++i)
        dp[i][n] = i;

      // empty left substring case
      for (int j = 1; j <= n; ++j)
        dp[0][n - j] = j;


      for (int i = 0; i < n; ++i) {
        char c = s[i];
        for (int j = n - 1; j > i; --j) {
          if (c == s[j])
            dp[i+1][j] = dp[i][j+1];
          else
            // insert s[i] before j or s[j] after i
            dp[i+1][j] = 1 + min(dp[i][j], dp[i+1][j+1]);
        }
      }

      uint16_t res = dp[n][n];
      for (int i = 0; i < n; ++i)
        res = min(res, min(dp[i][i], dp[i][i+1]));

      return res;
    }
};


int main() {
  EXECS(Solution::minInsertions);
  return 0;
}