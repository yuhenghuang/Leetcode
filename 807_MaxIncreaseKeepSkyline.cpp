#include "utils.hpp"

class Solution {
  public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
      int m = grid.size(), n = grid[0].size();
      vector<int> row_max(m), col_max(n);

      for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j) {
          if (grid[i][j]>row_max[i])
            row_max[i] = grid[i][j];
          if (grid[i][j]>col_max[j])
            col_max[j] = grid[i][j];
        }

      /*
      vector<vector<bool>> highest(m, vector<bool>(n, false));
      for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j) 
          highest[i][j] = grid[i][j] == row_max[i] || grid[i][j] == col_max[j];
      */
      
      int res = 0;
      for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j) 
          // if (!highest[i][j])
            res += min(row_max[i], col_max[j]) - grid[i][j];

      return res;
    }
};


int main() {

  RUN(Solution::maxIncreaseKeepingSkyline);

  return 0;
}