#include "utils.hpp"

class Solution {
  public:
    vector<vector<int>> generateMatrix(int n) {
      vector<vector<int>> res(n, vector<int>(n));

      static const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

      int num = 0, __max = n * n;
      
      int i_old = 0, j_old = -1, d = 0;
      while (num < __max) {
        int i = i_old + dir[d][0], j = j_old + dir[d][1];
        if (i<0 || i==n || j<0 || j==n || res[i][j]) {
          d = (d+1) % 4;
          continue;
        }
        res[i][j] = ++num;
        i_old = i;
        j_old = j;
      }

      return res;
    }
};


int main() {
  UFUNC(Solution::generateMatrix);
  return 0;
}