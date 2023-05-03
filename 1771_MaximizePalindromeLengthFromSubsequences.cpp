#include <local_leetcode.hpp>

class Solution {
  public:
    int longestPalindrome(string word1, string word2) {
      // wrong answer
      // intermediate palindrome doesn't have to cross word1 and 2


      int m = word1.size();
      int n = word2.size();

      int dp[m+1][n+1];

      dp[m][n] = 0;

      // todo: fix
      for (int i = 0; i < m; ++i)
        dp[i][n] = 1;

      for (int j = 0; j < n; ++j)
        dp[m][j] = 1;

      for (int k = 1; k < m + n; ++k)
        for (int i = min(m-1, m+n-k-1); i + k >= m && i >= 0; --i) {
          int j = n - (i + k - m) - 1;

          dp[i][j] = max(max(dp[i+1][j], dp[i][j+1]), word1[i] == word2[n-j-1] ? (dp[i+1][j+1] + 2) : 0);
        }

      return (dp[0][0] < 2) ? 0 : dp[0][0];
    }
};


int main() {
  EXECS(Solution::longestPalindrome);
  return 0;
}