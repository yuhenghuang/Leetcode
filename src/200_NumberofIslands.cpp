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
    static constexpr int dirs[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

    void dfs(int i, int j, int m, int n, vector<vector<bool>>& seen, const vector<vector<char>>& grid) {
      if (i < 0 || i >= m || j < 0 || j >= n || seen[i][j] || grid[i][j] == '0')
        return;

      seen[i][j] = true;
      for (auto& d : dirs)
        dfs(i + d[0], j + d[1], m, n, seen, grid);
    }

  public:
    int numIslands(vector<vector<char>>& grid) {
      int m = grid.size();
      int n = m == 0 ? 0 : grid[0].size();

      UnionFind uf(m * n);

      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (grid[i][j] == '1')
            for (int k = 0; k < 2; ++k) {
              int r = i + dirs[k][0];
              int c = j + dirs[k][1];

              if (r < m && c < n && grid[r][c] == '1')
                uf.join(i * n + j, r * n + c);
            }

      // count unique parents of islands
      unordered_set<int> islands;

      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (grid[i][j] == '1')
            islands.insert(uf.find(i * n + j));

      return islands.size();
    }
    int numIslandsDFS(vector<vector<char>>& grid) {
      int m = grid.size();
      int n = m == 0 ? 0 : grid[0].size();

      vector<vector<bool>> seen(m, vector<bool>(n));

      int res = 0;
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (grid[i][j] == '1' && !seen[i][j]) {
            dfs(i, j, m, n, seen, grid);
            ++res;
          }

      return res;
    }
};


int main() {
  EXECS(Solution::numIslands);
  EXECS(Solution::numIslandsDFS);
  return 0;
}
