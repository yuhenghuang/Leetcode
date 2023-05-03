#include <local_leetcode.hpp>

class Solution {
  public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
      constexpr int mod = 1e9 + 7;

      int m = grid.size();
      int n = grid[0].size();

      int dp[m][n][k];
      memset(dp, 0, sizeof(dp));

      int sum = grid[0][0];

      dp[0][0][sum % k] = 1;

      for (int i = 1; i < m; ++i) {
        sum = (sum + grid[i][0]) % k;
        dp[i][0][sum] = 1;
      }

      sum = grid[0][0];
      for (int j = 1; j < n; ++j) {
        sum = (sum + grid[0][j]) % k;
        dp[0][j][sum] = 1;
      }

      for (int i = 1; i < m; ++i)
        for (int j = 1; j < n; ++j)
          for (int d = 0; d < k; ++d) {
            // remainder such that (r + grid[i][j]) % k == d
            int r = ((d - grid[i][j]) % k + k) % k;

            int res = dp[i-1][j][r] + dp[i][j-1][r];

            // avoid expensive modular operation and 64bit integer
            if (res > mod)
              res -= mod;

            
            dp[i][j][d] = res;
          }

      return dp[m-1][n-1][0];
    }
};


int main() {
  EXECS(Solution::numberOfPaths);
  return 0;
}