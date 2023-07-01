#include <local_leetcode.hpp>

class Solution {
  public:
    int countNegatives(vector<vector<int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();

      int res = 0;

      for (int i = m - 1, j = 0; i >= 0 && j < n; --i) {
        for (; j < n && grid[i][j] >= 0; ++j);

        res += n - j;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::countNegatives);
  return 0;
}