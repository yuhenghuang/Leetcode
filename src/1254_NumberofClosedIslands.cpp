#include <local_leetcode.hpp>

class Solution {
  public:
    int closedIsland(vector<vector<int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();

      constexpr pair<int, int> dirs[4] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

      bool seen[100][100];
      memset(seen, 0, sizeof(seen));

      // true -> wall encountered
      function<bool (int, int)> dfs = [m, n, &dirs, &seen, &grid, &dfs] (int i, int j) -> bool {
        if (i == -1 || i == m || j == -1 || j == n)
          return true;
        else if (grid[i][j] || seen[i][j])
          return false;

        seen[i][j] = true;

        bool flag = false;
        for (auto& [v, h] : dirs)
          flag |= dfs(i + v, j + h);

        return flag;
      };

      int res = 0;
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (grid[i][j] == 0 && !seen[i][j] && !dfs(i, j))
            ++res;

      return res;
    }
};


int main() {
  EXECS(Solution::closedIsland);
  return 0;
}