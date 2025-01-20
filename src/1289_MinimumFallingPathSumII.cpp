#include <local_leetcode.hpp>

class Solution {
  public:
    int minFallingPathSum(vector<vector<int>>& grid) {
      int n = grid.size();
      int min_vals[n];

      vector<int> dp(grid[0].begin(), grid[0].end());

      for (int i = 1; i < n; ++i) {
        int temp = INT_MAX;
        for (int j = 1; j < n; ++j)
          min_vals[j] = temp = min(temp, dp[j-1]);

        temp = INT_MAX;
        for (int j = n - 2; j > 0; --j) {
          temp = min(temp, dp[j+1]);
          min_vals[j] = min(min_vals[j], temp);
        }

        min_vals[0] = min(temp, dp[1]);

        for (int j = 0; j < n; ++j)
          dp[j] = min_vals[j] + grid[i][j];
      }

      return *min_element(dp.begin(), dp.end());
    }
};


int main() {
  EXECS(Solution::minFallingPathSum);
  return 0;
}