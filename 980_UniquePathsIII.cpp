#define _NONTRIVIAL_SOLUTION_CTOR
#include "utils3.hpp"

class Solution {
  private:
    int m, n, res, target;
    int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    vector<vector<bool>> seen;

    void dfs(int i, int j, int sum, vector<vector<int>>& grid) {
      if (i<0 || i>=m || j<0 || j>=n || seen[i][j]) return;
      if (grid[i][j]==2) {
        if (sum==target)
          ++res;
        return;
      }

      seen[i][j] = true;

      for (int k=0; k<4; ++k)
        dfs(i+dir[k][0], j+dir[k][1], sum+1, grid);

      seen[i][j] = false;
    }
  public:
    int uniquePathsIII(vector<vector<int>>& grid) {
      m = grid.size();
      n = grid[0].size();
      res=0;
      target=0;
      seen = vector<vector<bool>>(m, vector<bool>(n, false));


      int st_i, st_j;
      for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
          if (grid[i][j]==0)
            ++target;
          else if (grid[i][j]==1) {
            st_i = i; 
            st_j = j;
          }
          else if (grid[i][j]==-1)
            seen[i][j] = true;

      dfs(st_i, st_j, -1, grid);

      return res;
    }
};


int main() {
  UFUNCS(Solution::uniquePathsIII);
  return 0;
}
