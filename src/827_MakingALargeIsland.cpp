#define _NONTRIVIAL_SOLUTION_CTOR
#include <set>
#include <numeric>
#include "utils3.hpp"

class Solution {
  private:
    int m, n;
    vector<int> parent, islands;
    vector<vector<bool>> seen;
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
  public:
    int largestIsland(vector<vector<int>>& grid) {
      m = grid.size();
      n = m==0 ? 0 : grid[0].size();
      parent = vector<int>(m*n);
      islands = vector<int>(m*n+1, 0); // size of island, indexed by parent. last position for outside of grid;
      seen = vector<vector<bool>>(m, vector<bool>(n, false));

      for (int i=0; i<m*n; ++i)
        parent[i] = i;

      for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
          dfs(i, j, i*n+j, grid);

      int res=0;
      for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
          res = max(res, (grid[i][j]) ? islands[parent[i*n+j]] : around(i, j));
      return res;
    }

    void dfs(int i, int j, int p, vector<vector<int>>& grid) {
      if (i<0 || i>=m || j<0 || j>=n || grid[i][j]==0 || seen[i][j])
        return;

      seen[i][j] = true;
      parent[i*n+j] = p;
      ++islands[p];
      for (int k=0; k<4; ++k)
        dfs(i+dir[k][0], j+dir[k][1], p, grid);
    }

    int around(int i, int j) {
      set<int> sur;
      for (int k=0; k<4; ++k)
        sur.insert(helper(i+dir[k][0], j+dir[k][1]));

      int res=1;
      for (const int& idx : sur)
        res += islands[idx];
      return res;
    }

    int helper(int i, int j) {
      // return parent id if legal
      if (i<0 || i>=m || j<0 || j>=n)
        return m*n; // last index of islands[]
      else 
        return parent[i*n + j];
    }

  private:
    void recursion(
      int r, int c, int p,
      const vector<vector<int>>& dirs, const vector<vector<int>>& grid, 
      vector<int>& parent, vector<int>& area, vector<vector<bool>>& seen) {
      // ...
      if (r < 0 || r >= n || c < 0 || c >= n || grid[r][c] == 0 || seen[r][c])
        return;

      seen[r][c] = true;
      parent[r*n + c] = p;
      ++area[p];

      for (const vector<int>& d : dirs)
        recursion(r + d[0], c + d[1], p, dirs, grid, parent, area, seen);
    }

  public:
    int largestIslandFast(vector<vector<int>>& grid) {
      n = grid.size();

      vector<vector<int>> dirs {{1,0}, {0,1}, {-1,0}, {0,-1}};
      vector<vector<bool>> seen(n, vector<bool>(n));

      vector<int> area(n * n);
      vector<int> parent(n * n);
      iota(parent.begin(), parent.end(), 0);

      int res = 0;
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          if (grid[i][j] && !seen[i][j])
            recursion(i, j, i*n + j, dirs, grid, parent, area, seen);

      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) 
          if (grid[i][j] == 0) {
            int tmp = 1;

            set<int> neighbors;
            for (vector<int>& d : dirs) {
              int r = i + d[0];
              int c = j + d[1];
              if (0 <= r && r < n && 0 <= c && c < n)
                neighbors.insert(parent[r*n + c]);
            }

            for (int p : neighbors)
              tmp += area[p];

            if (tmp > res)
              res = tmp;
          }
          else
            res = max(res, area[parent[i*n + j]]);

      return res;
    }
};


int main() {
  UFUNCS(Solution::largestIsland);
  UFUNCS(Solution::largestIslandFast);
  return 0;
}