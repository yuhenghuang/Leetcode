#include "utils2.hpp"

class Solution {
  private:
    int m, n;
    int dirs[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
      if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] == 0)
        return 0;

      visited[i][j] = true;

      int res = 1;
      for (auto dir : dirs) 
        res += dfs(i + dir[0], j + dir[1], grid, visited);

      return res;
    }

  public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      m = grid.size();
      n = m == 0 ? 0 : grid[0].size();

      vector<vector<bool>> visited(m, vector<bool>(n));

      int res = 0;
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (grid[i][j] && !visited[i][j])
            res = max(res, dfs(i, j, grid, visited));

      return res;
    }
};


int main() {
  UFUNC(Solution::maxAreaOfIsland);
  return 0;
}