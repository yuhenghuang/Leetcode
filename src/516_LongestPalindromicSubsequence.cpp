#include <local_leetcode.hpp>

class Solution {
  public:
    int longestPalindromeSubseq(string s) {
      int n = s.size();

      int dp[n][n];

      dp[0][0] = 1;
      for (int i = 1; i < n; ++i) {
        dp[i][i] = 1;
        dp[i][i-1] = 0;
      }

      for (int k = 1; k < n; ++k)
        for (int i = 0; i + k < n; ++i)
          dp[i][i+k] = max(max(dp[i][i+k-1], dp[i+1][i+k]), s[i] == s[i+k] ? (dp[i+1][i+k-1] + 2) : 0);

      return dp[0][n-1];
    }
};


int main() {
  EXECS(Solution::longestPalindromeSubseq);
  return 0;
}