#include "utils3.hpp"

/*

static int emm = [](){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

*/

class Solution {
  private:
    int dfs(int i, int j, int m, int n, vector<vector<int>>& dp, vector<vector<int>>& dungeon) {
      if (i < 0 || i >= m || j < 0 || j >= n)
        return INT_MAX;
      else if (dp[i][j] >= 0)
        return dp[i][j];

      return dp[i][j] = max(
        min(
          dfs(i+1, j, m, n, dp, dungeon),
          dfs(i, j+1, m, n, dp, dungeon)
        ) - dungeon[i][j],
        0
      );
    }

  public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
      int m=dungeon.size(), n= m==0? 0 : dungeon[0].size();
      if (n==0) return 0;

      vector<vector<int>> dp(m, vector<int>(n, 0));
      dp[m-1][n-1] = max(0, -dungeon[m-1][n-1]);
      for (int i=m-2; i>=0; --i)
        dp[i][n-1] = max(0, dp[i+1][n-1] - dungeon[i][n-1]);

      for (int j=n-2; j>=0; --j)
        dp[m-1][j] = max(0, dp[m-1][j+1] - dungeon[m-1][j]);

      for (int i=m-2; i>=0; --i)
        for (int j=n-2; j>=0; --j)
          dp[i][j] = max(0, min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j]);
      return dp[0][0]+1;
    }

    int calculateMinimumHPTop(vector<vector<int>>& dungeon) {
      int m = dungeon.size();
      int n = m == 0 ? 0 : dungeon[0].size();

      if (n == 0)
        return 0;

      vector<vector<int>> dp(m, vector<int>(n, -1));
      dp[m-1][n-1] = max(0, -dungeon[m-1][n-1]);

      return dfs(0, 0, m, n, dp, dungeon) + 1;
    }
};

int main() {
  UFUNCS(Solution::calculateMinimumHP);
  UFUNCS(Solution::calculateMinimumHPTop);
  return 0;
}