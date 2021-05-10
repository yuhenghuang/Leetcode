#include "utils2.hpp"

class Solution {
  public:
    int minDistance(string word1, string word2) {
      int m = word1.size(), n = word2.size();

      int dp[m+1][n+1];
      memset(dp, 0, (m+1) * (n+1) * sizeof(int));

      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) 
          dp[i+1][j+1] = word1[i] == word2[j] ? (dp[i][j] + 2) : max(dp[i+1][j], dp[i][j+1]);

      return m + n - dp[m][n];
    }
};


int main() {
  UFUNC(Solution::minDistance);
  return 0;
}