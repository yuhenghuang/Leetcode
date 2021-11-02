#include "utils3.hpp"

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& grid) {
      int m=grid.size(), n=grid[0].size();
      vector<vector<bool>> seen(m, vector<bool>(n, false));
      
      int i, j;
      queue<pair<int, int>> q;
      for (i=0; i<m; ++i)
        for (j=0; j<n; ++j) 
          if (grid[i][j]!=1) {
            seen[i][j] = true;
            if (grid[i][j]==2) 
              q.emplace(i, j);
          }

      int dir_row[4] = {1, -1, 0, 0};
      int dir_col[4] = {0, 0, 1, -1};

      int i_old, j_old, N;
      int res=0;
      bool move;
      while (!q.empty()) {
        N = q.size();
        move = false;
        while (N--) {
          auto &p = q.front();
          i_old = p.first;
          j_old = p.second;
          q.pop();
          for (int k=0; k<4; ++k) {
            i = i_old + dir_row[k];
            j = j_old + dir_col[k];
            if (i<0 || i>=m || j<0 || j>=n || seen[i][j]) continue;
            move = true;
            q.emplace(i, j);
            seen[i][j] = true;
          }
        }
        if (move)
          ++res;
      }

      for (i=0; i<m; ++i)
        for (j=0; j<n; ++j)
          if (!seen[i][j])
            return -1;
      return res;
    }
};

int main() {
  UFUNCS(Solution::orangesRotting);
  return 0;
}