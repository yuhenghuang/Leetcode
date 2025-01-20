#include <local_leetcode.hpp>

class Solution {
  public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
      const int m = img.size();
      const int n = img[0].size();

      int prefix[m+1][n+1];

      for (int i = 0; i <= m; ++i)
        prefix[i][0] = 0;

      for (int j = 0; j <= n; ++j)
        prefix[0][j] = 0;

      for (int i = 0; i < m; ++i) 
        for (int j = 0; j < n; ++j) 
          prefix[i+1][j+1] = img[i][j] + prefix[i+1][j] + prefix[i][j+1] - prefix[i][j];

      vector<vector<int>> res(m, vector<int>(n));

      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
          int x1 = max(i - 1, 0);
          int y1 = max(j - 1, 0);

          int x2 = min(i + 2, m);
          int y2 = min(j + 2, n);

          int n_cells = (x2 - x1) * (y2 - y1);

          res[i][j] = (prefix[x2][y2] - prefix[x1][y2] - prefix[x2][y1] + prefix[x1][y1]) / n_cells;
        }

      return res;
    }
};


int main() {
  EXECS(Solution::imageSmoother);
  return 0;
}