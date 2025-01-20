#include <local_leetcode.hpp>


class UnionFind {
  private:
    vector<int> parent;
    vector<int> rank;

  public:
    UnionFind(int n): parent(n, -1), rank(n) { }

    int find(int p) {
      if (parent[p] == -1)
        return p;

      return parent[p] = find(parent[p]);
    }

    void join(int p, int q) {
      p = find(p);
      q = find(q);

      if (p != q) {
        if (rank[p] < rank[q])
          parent[p] = q;
        else if (rank[p] > rank[q])
          parent[q] = p;
        else {
          parent[q] = p;
          ++rank[p];
        }
      }
    }
};


class Solution {
  private:
    int m, n;
    static constexpr int dirs[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
      if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] == 0)
        return 0;

      visited[i][j] = true;

      int res = 1;
      for (auto& dir : dirs) 
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

    int maxAreaOfIslandUF(vector<vector<int>>& grid) {
      int m = grid.size();
      int n = m == 0 ? 0 : grid[0].size();

      UnionFind uf(m * n);

      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (grid[i][j] == 1)
            for (int k = 0; k < 2; ++k) {
              int r = i + dirs[k][0];
              int c = j + dirs[k][1];

              if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1)
                uf.join(i * n + j, r * n + c);
            }

      vector<int> areas(m * n);

      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (grid[i][j])
            ++areas[uf.find(i * n + j)];

      return *max_element(areas.begin(), areas.end());
    }
};


int main() {
  EXECS(Solution::maxAreaOfIsland);
  EXECS(Solution::maxAreaOfIslandUF);
  return 0;
}