#include <local_leetcode.hpp>

// inherit std::iterator to activate necessary typedefs
class LayerIterator :
  public std::iterator<forward_iterator_tag, int>
{
  private:
    typedef LayerIterator self;

    // directions
    static int dirs[4][2];

    // matrix
    vector<vector<int>>& grid;

    // layer
    const int layer;

    // direction index (0 ~ 3)
    int d;

    int i; // row index
    int j; // column index

    bool notBetween(int x, int l, int r) { return x < l || x > r; }

  public:
    LayerIterator(vector<vector<int>>& _grid, int _layer): 
      grid(_grid), layer(_layer),
      d(0), i(layer), j(layer)
    { }

    // implement ++iter for std::advance
    self& operator++() {
      // if next step is over bounds, change direction
      if (
        notBetween(i + dirs[d][0], layer, (int) grid.size() - layer - 1) ||
        notBetween(j + dirs[d][1], layer, (int) grid[0].size() - layer - 1)
      ) {
        d = (d + 1) % 4;
      }

      i += dirs[d][0];
      j += dirs[d][1];

      return *this;
    }

    // implement *iter
    reference operator*() { return grid[i][j]; }
};

int LayerIterator::dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};


class Solution {
  public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
      int m = grid.size();
      int n = grid[0].size();

      vector<vector<int>> res(m, vector<int>(n));

      for (int l = 0; l < min(m, n) / 2; ++l) {
        LayerIterator i(grid, l);
        LayerIterator j(res, l);

        // perimeter
        int p = (m + n - 2 - l * 4) * 2;

        std::advance(i, k % p);

        // write to new matrix p times
        for (int d = 0; d < p; ++d, ++i, ++j) 
          *j = *i;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::rotateGrid);
  return 0;
}