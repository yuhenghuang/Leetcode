#include <local_leetcode.hpp>

class Solution {
  public:
    bool hasValidPath(vector<vector<char>>& grid) {
      int m = grid.size();
      int n = grid[0].size();

      // early stop
      if (((m + n) & 1) == 0 || grid[0][0] == ')' || grid[m-1][n-1] == '(')
        return false;

      int l = (m + n + 1) / 2;

      // row, column, count of left ( - right )
      bool dp[m][n][l];

      memset(dp, 0, sizeof(dp));

      dp[0][0][1] = true;

      int temp = 1;
      for (int i = 1; i < m; ++i) {
        temp += grid[i][0] == '(' ? 1 : -1;

        if (temp >= 0 && temp < l)
          dp[i][0][temp] = true;
        else
          break; // crucial!!!
      }

      temp = 1;
      for (int j = 1; j < n; ++j) {
        temp += grid[0][j] == '(' ? 1 : -1;

        if (temp >= 0 && temp < l)
          dp[0][j][temp] = true;
        else
          break;
      }

      for (int i = 1; i < m; ++i)
        for (int j = 1; j < n; ++j)
          if (grid[i][j] == '(') {
            for (int k = 0; k + 1 < l; ++k)
              if (dp[i-1][j][k] || dp[i][j-1][k])
                dp[i][j][k+1] = true;
          }
          else {
            for (int k = 1; k < l; ++k)
              if (dp[i-1][j][k] || dp[i][j-1][k])
                dp[i][j][k-1] = true;
          }

      return dp[m-1][n-1][0];
    }
};


int main() {
  EXECS(Solution::hasValidPath);
  return 0;
}