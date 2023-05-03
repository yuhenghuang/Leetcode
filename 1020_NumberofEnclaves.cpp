#include <local_leetcode.hpp>

class Solution {
  public:
    int numEnclaves(vector<vector<int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();

      vector<vector<bool>> seen(m, vector<bool>(n));

      constexpr pair<int, int> dirs[4] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

      function<int (int, int)> dfs = [m, n, &seen, &grid, &dirs, &dfs] (int i, int j) -> int {
        if (i < 0 || i >= m || j < 0 || j >= n)
          return -30000;
        else if (grid[i][j] == 0 || seen[i][j])
          return 0;

        seen[i][j] = true;
        int res = 1;
        for (auto [v, h] : dirs)
          res += dfs(i + v, j + h);

        return res;
      };

      int res = 0;
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (grid[i][j] && !seen[i][j])
            res += max(0, dfs(i, j));

      return res;
    }
};


int main() {
  EXECS(Solution::numEnclaves);
  return 0;
}