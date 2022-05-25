#include <local_leetcode.hpp>

class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      int m = obstacleGrid.size();
      int n = obstacleGrid[0].size();

      if (obstacleGrid[0][0] + obstacleGrid[m-1][n-1] > 0)
        return 0;

      vector<vector<int>> dp(m, vector<int>(n));

      for (int i = 0; i < m; ++i)
        if (obstacleGrid[i][0] == 0)
          dp[i][0] = 1;
        else
          break;

      for (int j = 1; j < n; ++j)
        if (obstacleGrid[0][j] == 0)
          dp[0][j] = 1;
        else
          break;

      for (int i = 1; i < m; ++i)
        for (int j = 1; j < n; ++j) {
          dp[i][j] = (obstacleGrid[i][j-1] == 1 ? 0 : dp[i][j-1]) + \
            (obstacleGrid[i-1][j] == 1 ? 0 : dp[i-1][j]);
        }

      return dp[m-1][n-1];
    }
};


int main() {
  EXECS(Solution::uniquePathsWithObstacles);
  return 0;
}