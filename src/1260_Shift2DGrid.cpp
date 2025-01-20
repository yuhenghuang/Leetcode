#include <local_leetcode.hpp>

class GridIterator: public iterator<forward_iterator_tag, int> {
  private:
    typedef GridIterator self;

    int i, j;
    int m, n;
    vector<vector<int>>& grid;

  public:
    GridIterator(vector<vector<int>>& _grid): i(0), j(0), grid(_grid) {
      m = grid.size();
      n = grid[0].size();
    }

    self& operator++() {
      if (++j == n) {
        j = 0;
        ++i;
      }

      if (i == m)
        i = 0;

      return *this;
    }

    int& operator*() { return grid[i][j]; }
};


class Solution {
  public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
      const int m = grid.size();
      const int n = grid[0].size();

      vector<vector<int>> res(m, vector<int>(n));

      k %= (m * n);

      GridIterator i(grid);
      GridIterator j(res);

      advance(j, k);

      for (int p = 0; p < m * n; ++p) {
        *j = *i;

        ++i;
        ++j;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::shiftGrid);
  return 0;
}