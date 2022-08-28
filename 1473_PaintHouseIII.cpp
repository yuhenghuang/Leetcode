#include <local_leetcode.hpp>

class Solution {
  public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
      if (target > m)
        return -1;

      // house, color, neighbors -> cost
      int dp[m][n][target];
    
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          for (int k = 0; k < target; ++k)
            dp[i][j][k] = INT_MAX;

      // initialize conditions of house[0]
      if (houses[0] == 0) {
        for (int j = 0; j < n; ++j)
          dp[0][j][0] = cost[0][j];
      }
      else
        dp[0][houses[0] - 1][0] = 0;


      for (int i = 1; i < m; ++i) {
        int color = houses[i] - 1;
        if (color == -1) {
          for (int j = 0; j < n; ++j) // color of left neighbor
            for (int k = 0; k < target; ++k) // # of neighbors
              if (dp[i-1][j][k] != INT_MAX)
                for (int l = 0; l < n; ++l) { // color of current house
                  if (l == j)
                    dp[i][l][k] = min(dp[i][l][k], dp[i-1][j][k] + cost[i][l]);
                  else if (k + 1 < target)
                    dp[i][l][k+1] = min(dp[i][l][k+1], dp[i-1][j][k] + cost[i][l]);
                }
        }
        else { // house[i] color fixed
          for (int j = 0; j < n; ++j)
              for (int k = 0; k < target; ++k)
                if (dp[i-1][j][k] != INT_MAX) {
                  if (color == j)
                    dp[i][color][k] = min(dp[i][color][k], dp[i-1][j][k]);
                  else if (k + 1 < target)
                    dp[i][color][k+1] = min(dp[i][color][k+1], dp[i-1][j][k]);
                }
        }
      }

      int res = INT_MAX;
      for (int j = 0; j < n; ++j)
        res = min(res, dp[m-1][j][target-1]);

      return res == INT_MAX ? -1 : res;
    }
};


int main() {
  EXECS(Solution::minCost);
  return 0;
}