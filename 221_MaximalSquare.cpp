#include <local_leetcode.hpp>

class Solution {
  public:
    int maximalSquare(vector<vector<char>>& matrix) {
      int m = matrix.size();
      int n = matrix[0].size();

      int res = 0;
      int dp[m][n];

      for (int i = 0; i < m; ++i) {
        dp[i][0] = matrix[i][0] - '0';

        if (dp[i][0] > res)
          res = dp[i][0];
      }

      for (int j = 1; j < n; ++j) {
        dp[0][j] = matrix[0][j] - '0';

        if (dp[0][j] > res)
          res = dp[0][j];
      }

      for (int i = 1; i < m; ++i)
        for (int j = 1; j < n; ++j) {
          if (matrix[i][j] == '0')
            dp[i][j] = 0;
          else {
            int h = dp[i-1][j];
            int w = dp[i][j-1];

            if (h == w) 
              dp[i][j] = h + (dp[i-h][j-w] > 0 ? 1 : 0);
            else
              dp[i][j] = 1 + min(h, w);
          }


          if (dp[i][j] > res)
            res = dp[i][j];
        }

      return res * res;
    }
};


int main() {
  EXECS(Solution::maximalSquare);
  return 0;
}