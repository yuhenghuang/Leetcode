#include <vector>
using namespace std;

class Solution {
  private:
    int m, n;
    vector<vector<bool>> visited;
    int dir[6][4] ={{0, 1, 0, -1},
                    {1, 0, -1, 0},
                    {1, 0, 0, -1},
                    {0, 1, 1, 0},
                    {-1, 0, 0, -1},
                    {-1, 0, 0, 1}};
  public:
    bool hasValidPath(vector<vector<int>>& grid) {
      m = grid.size();
      n = m==0 ? 0 : grid[0].size();
      visited = vector<vector<bool>>(m, vector<bool>(n, false));

      int tmp_1 = m-1, tmp_2 = n-1;
      int tmp_3 = 0, tmp_4 = 0;
      
      bool tmp = dfs(grid, 0, 0, tmp_1, tmp_2);
      for (auto& vec : visited)
        vec = vector<bool>(n, false);
      return tmp && dfs(grid, m-1, n-1, tmp_3, tmp_4);
    }

  bool dfs(vector<vector<int>>& grid, int i, int j, int& x, int& y) {
    if (i<0 || i>=m || j<0 || j>=n || visited[i][j]) return false;
    else if (i==x && j==y) return true;
    visited[i][j] = true;
    return dfs(grid, i + dir[grid[i][j]-1][0], j + dir[grid[i][j]-1][1], x, y) || 
           dfs(grid, i + dir[grid[i][j]-1][2], j + dir[grid[i][j]-1][3], x, y);
  }
};