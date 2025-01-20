#include "utils2.hpp"

class Solution {
  private:
    int dp(int k, int i1, int i2, const vector<vector<int>>& grid, vector<vector<vector<int>>>& memo) {
      int j1 = k-i1, j2 = k-i2;
      if (i1<0 || j1<0 || i2<0 || j2<0 || grid[i1][j1]==-1 || grid[i2][j2]==-1)
        return INT_MIN+1; // differentiate states of memo
      else if (memo[k][i1][i2]!=INT_MIN)
        return memo[k][i1][i2];

      int res = grid[i1][j1] + (i1!=i2 ? grid[i2][j2] : 0);
      res += max(
        max(dp(k-1, i1, i2, grid, memo), dp(k-1, i1-1, i2-1, grid, memo)),
        max(dp(k-1, i1-1, i2, grid, memo), dp(k-1, i1, i2-1, grid, memo))
      );

      memo[k][i1][i2] = res;
      return res;
    }

  public:
    int cherryPickupTD(vector<vector<int>>& grid) {
      // top-down
      int n = grid.size();

      vector<vector<vector<int>>> memo(n*2-1, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
      if (grid[0][0] >= 0)
        memo[0][0][0] = grid[0][0];
      else
        memo[0][0][0]++;

      return max(dp(n*2-2, n-1, n-1, grid, memo), 0);
    }

    int cherryPickup(vector<vector<int>>& grid) {
      int n = grid.size();

      vector<vector<int>> dp(n, vector<int>(n, INT_MIN));

      dp[0][0] = grid[0][0];

      for (int k=1; k<2*n-1; ++k) {
        vector<vector<int>> dp2(n, vector<int>(n, INT_MIN));

        for (int i=max(0, k-n+1); i<=min(k, n-1); ++i)
          for (int j=max(0, k-n+1); j<=min(k, n-1); ++j) {
            if (grid[i][k-i]<0 || grid[j][k-j]<0) continue;
            int val = grid[i][k-i] + (i!=j ? grid[j][k-j] : 0);
            for (int pi=i-1; pi<=i; ++pi)
              for (int pj=j-1; pj<=j; ++pj)
                if (pi>=0 && pj>=0)
                  dp2[i][j] = max(dp2[i][j], dp[pi][pj] + val);
          }

        dp = std::move(dp2);
      }

      return max(dp[n-1][n-1], 0);
    }
};


int main() {
  {
    UFUNC(Solution::cherryPickup);
  }
  {
    UFUNC(Solution::cherryPickupTD);
  }
  return 0;
}