#include <local_leetcode.hpp>

class Solution {
  public:
    int minDistanceOld(string word1, string word2) {
      int m = word1.size(), n = word2.size();

      // longest common sequences
      int dp[m+1][n+1];
      memset(dp, 0, (m+1) * (n+1) * sizeof(int));

      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) 
          dp[i+1][j+1] = word1[i] == word2[j] ? (dp[i][j] + 2) : max(dp[i+1][j], dp[i][j+1]);

      return m + n - dp[m][n];
    }

    int minDistance(string word1, string word2) {
      int m = word1.size(), n = word2.size();

      // distance (i.e. num. of deletions)
      int dp[m+1][n+1];

      dp[0][0] = 0;

      for (int i = 0; i < m; ++i)
        dp[i+1][0] = i + 1;

      for (int j = 0; j < n; ++j)
        dp[0][j+1] = j + 1;

      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          dp[i+1][j+1] = word1[i] == word2[j] ? dp[i][j] : ( min(dp[i+1][j], dp[i][j+1]) + 1 );

      return dp[m][n];
    }
};


int main() {
  EXECS(Solution::minDistance);
  EXECS(Solution::minDistanceOld);
  return 0;
}