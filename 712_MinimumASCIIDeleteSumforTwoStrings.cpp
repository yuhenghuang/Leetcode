#include <local_leetcode.hpp>

class Solution {
  public:
    int minimumDeleteSum(string s1, string s2) {
      int m = s1.size();
      int n = s2.size();

      int dp[m+1][n+1]; // max sum of common subsequence

      int total = s2[0];
      for (int i = 0; i <= m; ++i) {
        total += s1[i];
        dp[i][0] = 0;
      }

      for (int j = 1; j <= n; ++j) {
        total += s2[j];
        dp[0][j] = 0;
      }

      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
          if (s1[i] == s2[j])
            dp[i+1][j+1] = dp[i][j] + s1[i];
          else
            dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
        }

      return total - dp[m][n] * 2;
    }

    int minimumDeleteSumMin(string s1, string s2) {
      int m = s1.size();
      int n = s2.size();

      int dp[m+1][n+1]; // min sum of chars other than common subsequence

      dp[0][0] = 0;

      for (int i = 1; i <= m; ++i)
        dp[i][0] = s1[i-1] + dp[i-1][0];

      for (int j = 1; j <= n; ++j)
        dp[0][j] = s2[j-1] + dp[0][j-1];

      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
          if (s1[i] == s2[j])
            dp[i+1][j+1] = dp[i][j];
          else
            dp[i+1][j+1] = min(dp[i+1][j] + s2[j], dp[i][j+1] + s1[i]);
        }

      return dp[m][n];
    }
};


int main() {
  EXECS(Solution::minimumDeleteSum);
  EXECS(Solution::minimumDeleteSumMin);
  return 0;
}