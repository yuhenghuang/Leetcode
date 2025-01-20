#include "utils.hpp"


class Solution {
  public:
    int cherryPickup(vector<vector<int>>& grid) {
      int m = grid.size(), n = grid[0].size();

      vector<vector<vector<int>>> memo(m+1, vector<vector<int>>(n, vector<int>(n, 0)));
      // int memo[m+1][n][n];
      // memset(memo, 0, (m+1)*n*n);
      
      int dir[3] = {-1, 0, 1};
      for (int k=m; k>0; --k) {
        for (int i=0; i<n-1; ++i)
          for (int j=i+1; j<n; ++j) 
            for (int l=0; l<9; ++l) {
              int i_prev = i+dir[l/3];
              int j_prev = j+dir[l%3];

              if (i_prev>=j_prev || i_prev<0 || j_prev>=n) 
                continue;

              memo[k-1][i_prev][j_prev] = max(memo[k-1][i_prev][j_prev], memo[k][i][j]+grid[k-1][i_prev]+grid[k-1][j_prev]);
            }
      }

      return memo[0][0][n-1];
    }
};


int main() {
  UFUNC(Solution::cherryPickup);
  return 0;
}