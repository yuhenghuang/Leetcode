#include <local_leetcode.hpp>

class Solution {
  private:
    int fall(int i, int j, int n, vector<vector<int>>& grid) {
      if (i == grid.size())
        return j;

      // column of neighbor index needed to check the direction of board
      int k = j + grid[i][j];
      if (k < 0 || k == n || grid[i][k] != grid[i][j])
        return -1;

      return fall(i + 1, k, n, grid);
    }

    int fall(int i, int j, int n, vector<vector<int>>& dp, vector<vector<int>>& grid) {
      if (i == grid.size())
        return j;

      if (dp[i][j] < n)
        return dp[i][j];

      // column of neighbor index needed to check the direction of board
      int k = j + grid[i][j];
      if (k < 0 || k == n || grid[i][k] != grid[i][j])
        return dp[i][j] = -1;

      return dp[i][j] = fall(i + 1, k, n, grid);
    }

  public:
    vector<int> findBall(vector<vector<int>>& grid) {
      int n = grid[0].size();

      vector<int> res;
      for (int j = 0; j < n; ++j)
        res.push_back(fall(0, j, n, grid));

      return res;
    }

    vector<int> findBallDP(vector<vector<int>>& grid) {
      // any necessity for DP???

      int n = grid[0].size();

      vector<vector<int>> dp(grid.size(), vector<int>(n, n));

      vector<int> res;
      for (int j = 0; j < n; ++j)
        res.push_back(fall(0, j, n, dp, grid));

      return res;
    }
};


int main() {
  EXECS(Solution::findBall);
  EXECS(Solution::findBallDP);
  return 0;
}
