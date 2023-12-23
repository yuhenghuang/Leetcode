#include <local_leetcode.hpp>

class Solution {
  public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
      const int m = grid.size();
      const int n = grid[0].size();

      vector<int> rowOnes(m), colOnes(n);

      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (grid[i][j]) {
            ++rowOnes[i];
            ++colOnes[j];
          }

      vector<vector<int>> res(m, vector<int>(n));

      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          res[i][j] = ((rowOnes[i] + colOnes[j]) << 1) - (m + n);

      return res;
    }
};


int main() {
  EXECS(Solution::onesMinusZeros);
  return 0;
}