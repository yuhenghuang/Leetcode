#define _LL_FLATTEN_2D
#include <local_leetcode.hpp>

class Solution {
  private:
    int m, n;
    static constexpr int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  
    void dfs(int i, int j, int h, vector<vector<int>>& mat, vector<vector<bool>>& visited) {
      if (i<0 || i>=m || j<0 || j>=n || visited[i][j] || mat[i][j] < h)
        return;
      
      visited[i][j] = true;
      for (int k=0; k<4; ++k)
        dfs(i + dir[k][0], j + dir[k][1], mat[i][j], mat, visited);
    }

    vector<vector<bool>> bfs(int m, int n, const vector<vector<int>>& mat, queue<pair<int, int>>& q) {
      vector<vector<bool>> seen(m, vector<bool>(n));

      while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        if (seen[i][j])
          continue;
        
        seen[i][j] = true;

        for (auto& d : dir) {
          int r = i + d[0];
          int c = j + d[1];

          if (r >= 0 && r < m && c >= 0 && c < n && !seen[r][c] && mat[r][c] >= mat[i][j])
            q.emplace(r, c);
        }
      }

      return seen;
    }
  
  public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
      m = matrix.size();
      n = m==0 ? 0 : matrix[0].size();
      
      vector<vector<bool>> pacific(m, vector<bool>(n));
      vector<vector<bool>> atlantic(m, vector<bool>(n));
      
      for (int i=0; i<m; ++i) {
        dfs(i, 0, 0, matrix, pacific);
        dfs(i, n-1, 0, matrix, atlantic);
      }
      
      for (int j=0; j<n; ++j) {
        dfs(0, j, 0, matrix, pacific);
        dfs(m-1, j, 0, matrix, atlantic);
      }
      
      vector<vector<int>> res;
      for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
          if (pacific[i][j] && atlantic[i][j])
            res.push_back({i, j});
      
      return res;
    }

    vector<vector<int>> pacificAtlanticBFS(vector<vector<int>>& matrix) {
      const int m = matrix.size();
      const int n = m == 0 ? 0 : matrix[0].size();

      // one queue is enough
      // but.. don't want to write same loop twice.
      queue<pair<int, int>> q1, q2;
      for (int i = 0; i < m; ++i) {
        q1.emplace(i, 0);
        q2.emplace(i, n-1);
      }

      for (int j = 0; j < n; ++j) {
        q1.emplace(0, j);
        q2.emplace(m-1, j);
      }

      auto&& pacific = bfs(m, n, matrix, q1);
      auto&& atlantic = bfs(m, n, matrix, q2);

      vector<vector<int>> res;
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (pacific[i][j] && atlantic[i][j])
            res.push_back({i, j});
      
      return res;
    }
};


int main() {
  EXECS(Solution::pacificAtlantic);
  EXECS(Solution::pacificAtlanticBFS);
  return 0;
}
