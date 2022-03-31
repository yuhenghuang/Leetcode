#include <local_leetcode.hpp>

class Solution {
  public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
      int m = artifacts.size();

      // count of cells covering an artifact
      vector<int> cells(m);

      vector<vector<int>> grid(n, vector<int>(n, -1));

      for (int k = 0; k < m; ++k) {
        vector<int>& a = artifacts[k];
        for (int i = a[0]; i <= a[2]; ++i)
          for (int j = a[1]; j <= a[3]; ++j)
            grid[i][j] = k;

        cells[k] = (a[2] - a[0] + 1) * (a[3] - a[1] + 1);
      }

      int res = 0;
      for (auto& d : dig) {
        int k = grid[d[0]][d[1]];

        if (k >= 0 && --cells[k] == 0)
          ++res;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::digArtifacts);
  return 0;
}