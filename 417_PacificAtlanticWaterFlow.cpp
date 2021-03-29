#include "utils2.hpp"

class Solution {
  private:
    int m, n;
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  
    void dfs(int i, int j, int h, vector<vector<int>>& mat, vector<vector<bool>>& visited) {
      if (i<0 || i>=m || j<0 || j>=n || visited[i][j] || mat[i][j] < h)
        return;
      
      visited[i][j] = true;
      for (int k=0; k<4; ++k)
        dfs(i + dir[k][0], j + dir[k][1], mat[i][j], mat, visited);
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
};


int main() {
  UFUNC(Solution::pacificAtlantic);
  return 0;
}