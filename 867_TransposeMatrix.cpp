#include <local_leetcode.hpp>

class Solution {
  public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
      const int m = matrix.size();
      const int n = matrix[0].size();

      if (m == n) {
        for (int i = 1; i < n; ++i)
          for (int j = 0; j < i; ++j)
            swap(matrix[i][j], matrix[j][i]);

        return matrix;
      }
      else {
        vector<vector<int>> res(n, vector<int>(m));

        for (int i = 0; i < m; ++i)
          for (int j = 0; j < n; ++j)
            res[j][i] = matrix[i][j];

        return res;
      }
    }
};


int main() {
  EXECS(Solution::transpose);
  return 0;
}