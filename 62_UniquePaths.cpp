#include <local_leetcode.hpp>

class Solution {
  public:
    int uniquePaths(int m, int n) {
      int dp[m][n];
      
      // initial conditions for leftmost column
      for (int i = 0; i < m; ++i)
        dp[i][0] = 1;

      // initial conditions for upmost row
      for (int j = 1; j < n; ++j)
        dp[0][j] = 1;


      for (int i = 1; i < m; ++i)
        for (int j = 1; j < n; ++j)
          dp[i][j] = dp[i-1][j] + dp[i][j-1];

      return dp[m-1][n-1];
    }
};


int main() {
  EXECS(Solution::uniquePaths);
  return 0;
}