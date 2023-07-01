#include <local_leetcode.hpp>

class Solution {
  public:
    int countPaths(vector<vector<int>>& grid) {
      typedef tuple<int, int, int> i3_t;

      constexpr int mod = 1e9 + 7;
      static constexpr int dirs[4][2] {{0,1}, {1,0}, {0,-1}, {-1,0}};

      const int m = grid.size();
      const int n = grid[0].size();

      int dp[m][n];
      memset(dp, 0, sizeof(dp));

      // number, row index, column index
      vector<i3_t> cells;

      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          cells.emplace_back(grid[i][j], i, j);

      // sort cell by number in descending order
      sort(
        cells.begin(), cells.end(),
        [] (const i3_t& p, const i3_t& q) { return get<0>(p) > get<0>(q); }
      );

      int res = 0;
      for (auto [v, i, j] : cells) {
        for (auto& d : dirs) {
          int r = i + d[0];
          int c = j + d[1];

          if (0 <= r && r < m && 0 <= c && c < n && v < grid[r][c])
            dp[i][j] = (dp[i][j] + dp[r][c]) % mod;
        }

        res += (++dp[i][j]);

        if (res > mod)
          res -= mod;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::countPaths);
  return 0;
}