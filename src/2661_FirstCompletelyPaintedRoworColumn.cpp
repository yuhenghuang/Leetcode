#include <local_leetcode.hpp>

class Solution {
  public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
      typedef pair<int, int> ii_t;

      const int m = mat.size();
      const int n = mat[0].size();

      vector<int> heights(n), widths(m);

      vector<ii_t> coords(m * n + 1);

      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          coords[mat[i][j]] = {i, j};

      for (int i = 0; i < (int) arr.size(); ++i) {
        auto [r, c] = coords[arr[i]];

        if (++widths[r] == n)
          return i;

        if (++heights[c] == m)
          return i;
      }

      return -1;
    }
};


int main() {
  EXECS(Solution::firstCompleteIndex);
  return 0;
}