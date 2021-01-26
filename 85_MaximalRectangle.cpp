#include "utils2.hpp"

class Solution {
  public:
    int maximalRectangleSimple(vector<vector<char>>& matrix) {
      int m = matrix.size();
      int n = m==0 ? 0 : matrix[0].size();

      vector<vector<int>> height(m+1, vector<int>(n));

      int res = 0;
      for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
          if (matrix[i][j]=='1') {
            int h = 255;
            height[i+1][j] = height[i][j] + 1;;

            int temp = 0;
            int k = 1;
            while (j-k+1>=0 && matrix[i][j-k+1]=='1') {
              h = min(height[i+1][j-k+1], h);
              temp = max(temp, h*k);
              ++k;
            }

            if (temp>res)
              res = temp;
          }

      return res;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
      int m = matrix.size();
      int n = m==0 ? 0 : matrix[0].size();

      vector<vector<int>> up_left(m+1, vector<int>(n+1));

      constexpr int mask = (1 << 8) - 1;

      int res = 0;

      for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
          if (matrix[i][j]=='1') {
            int up = (up_left[i][j+1] >> 8) + 1;
            int left = (up_left[i+1][j] & mask) + 1;

            up_left[i+1][j+1] = up << 8;
            up_left[i+1][j+1] ^= left;

            int temp = 0;
            temp = max(temp, max(up, left));

            int k = 2;
            while (k <= min(up, left) && matrix[i-k+1][j-k+1] == '1') {
              up = min(up, (up_left[i-k+1][j-k+2] >> 8) + k);
              left = min(left, (up_left[i-k+2][j-k+1] & mask) + k);

              temp = max(temp, k * max(up, left));
              ++k;
            }

            if (temp > res)
              res = temp;
          }

      return res;
    }
};


int main() {
  {
    UFUNC(Solution::maximalRectangle);
  }
  {
    UFUNC(Solution::maximalRectangleSimple);
  }
  return 0;
}