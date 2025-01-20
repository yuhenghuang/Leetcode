#include <local_leetcode.hpp>

class Solution {
  public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
      int m = matrix.size();
      int n = matrix[0].size();

      vector<int> diag(m + n - 1, -1);

      copy(matrix[0].begin(), matrix[0].end(), diag.begin() + (m - 1));

      for (int r = 1; r < m; ++r) {
        diag[m - r - 1] = matrix[r][0];

        for (int c = 1; c < n; ++c)
          if (diag[m - r - 1 + c] != matrix[r][c])
            return false;
      }

      return true;
    }
};


int main() {
  EXECS(Solution::isToeplitzMatrix);
  return 0;
}