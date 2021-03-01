#include "utils2.hpp"

class Solution {
  private:
    bool binarySearch(int i, int j, int m, int n, const vector<vector<int>>& mat, int target) {
      if (i > m || j > n)
        return false;
      else if (i==m && j==n)
        return mat[i][j] == target;

      int p = i + (m-i)/2, q = j + (n-j)/2;

      bool res = false;
      if (mat[p][q] >= target && binarySearch(i, j, p, q, mat, target))
        return true;
      
      if (mat[m][q] >= target && binarySearch(p+1, j, m, q, mat, target))
        return true;

      if (mat[p][n] >= target && binarySearch(i, q+1, p, n, mat, target))
        return true;

      if (i<m && j<n && mat[p+1][q+1] <= target)
        return binarySearch(p+1, q+1, m, n, mat, target);

      return false;
    }

  public:
    bool searchMatrixSlow(vector<vector<int>>& matrix, int target) {
      int m = matrix.size(), n = m==0 ? 0 : matrix[0].size();

      return binarySearch(0, 0, m-1, n-1, matrix, target);
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int m = matrix.size(), n = m==0 ? 0 : matrix[0].size();

      int i = 0, j = n-1;
      while (i < m && j >= 0) {
        if (matrix[i][j] > target)
          --j;
        else if (matrix[i][j] < target)
          ++i;
        else
          return true;
      }

      return false;
    }
};


int main() {
  UFUNC(Solution::searchMatrix);
  return 0;
}