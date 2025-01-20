#include "utils3.hpp"

class Solution {
  public:
    void setZeroes(vector<vector<int>>& matrix) {
      int m = matrix.size();
      int n = m == 0 ? 0 : matrix[0].size();

      // use first row and first column and one scalar 
      // to record zero rows and columns
      bool first_row = false;
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (matrix[i][j] == 0) {
            if (i == 0)
              first_row = true;
            else {
              matrix[0][j] = 0;
              matrix[i][0] = 0;
            }
          }

      for (int i = 1; i < m; ++i)
        if (matrix[i][0] == 0)
          for (int j = 1; j < n; ++j)
            matrix[i][j] = 0;

      for (int j = 0; j < n; ++j) {
        if (matrix[0][j] == 0)
          for (int i = 1; i < m; ++i)
            matrix[i][j] = 0;

        if (first_row)
          matrix[0][j] = 0;
      }
    }
};


int main() {
  UFUNCS(Solution::setZeroes);
  return 0;
}