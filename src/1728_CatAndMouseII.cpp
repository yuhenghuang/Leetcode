#include "utils2.hpp"

class Solution {
  private:
    int m, n;
    int dir[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    vector<vector<int>> memo_mouse, memo_cat;
    vector<vector<bool>> seen_mouse, seen_cat;


    // mouse i, j
    int roundMouse(int i, int j, int p, int q, int mj, int cj, const vector<string>& grid) {
      if (p<0 || p>=m || q<0 || q>=n || grid[p][q]=='#')
        return -1;
      else if (grid[p][q]=='F' || (i==p || j==q))
        return 0;
      else if (seen_cat[p][q])
        return 1;
      else if (memo_mouse[i*n+j][p*n+q]>=0)
        return memo_mouse[i*n+j][p*n+q];

      seen_mouse[i][j] = true;

      int res = 0;
      for (int d=0; d<4; ++d) {
        for (int k=1; k<=mj; ++k) {
          int temp = roundCat(i+dir[d][0]*k, j+dir[d][1]*k, p, q, mj, cj, grid);
          // wall or boundary
          if (temp < 0)
            break;
          // found opponent lost
          if (temp==0) {
            res = 1;
            break;
          }
        }
        if (res)
          break;
      }

      seen_mouse[i][j] = false;

      memo_mouse[i*n+j][p*n+q] = res;
      return res;
    }

    // cat p, q
    bool roundCat(int i, int j, int p, int q, int mj, int cj, const vector<string>& grid) {
      if (i<0 || i>=m || j<0 || j>=n || grid[i][j]=='#')
        return -1;
      else if (i==p && j==q || seen_mouse[i][j])
        return 1;
      else if (grid[i][j]=='F')
        return 0;
      else if (memo_cat[i*n+j][p*n+q]>=0)
        return memo_cat[i*n+j][p*n+q];

      seen_cat[p][q] = true;

      int res = 0;
      for (int d=0; d<4; ++d) {
        for (int k=1; k<=cj; ++k) {
          int temp = roundMouse(i, j, p+dir[d][0]*k, q+dir[d][1]*k, mj, cj, grid);
          // wall or boundary
          if (temp < 0)
            break;
          // found opponent lost
          if (temp==0) {
            res = 1;
            break;
          }
        }
        if (res)
          break;
      }

      seen_cat[p][q] = false;

      memo_cat[i*n+j][p*n+q] = res;
      return res;
    }

  public:
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
      m = grid.size();
      n = grid[0].size();

      memo_mouse = vector<vector<int>>(m*n, vector<int>(m*n, -1));
      memo_cat = vector<vector<int>>(m*n, vector<int>(m*n, -1));

      seen_mouse = vector<vector<bool>>(m, vector<bool>(n));
      seen_cat = vector<vector<bool>>(m, vector<bool>(n));
      
      int i, j, p, q;
      for (int r=0; r<m; ++r)
        for (int c=0; c<n; ++c)
          if (grid[r][c]=='M') {
            i = r; j = c;
          }
          else if (grid[r][c]=='C') {
            p = r; q = c;
          }

      return roundMouse(i, j, p, q, mouseJump, catJump, grid);
    }
};


int main() {
  UFUNC(Solution::canMouseWin);
  return 0;
}