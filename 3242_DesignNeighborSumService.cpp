#include <local_leetcode.hpp>

#define N 10


class NeighborSum {
  private:
    typedef pair<int, int> pii_t;

    int _grid[N+2][N+2];
    int diag[N][N];
    int adja[N][N];

    unordered_map<int, pii_t> dict;

  public:
    NeighborSum(vector<vector<int>>& grid): _grid{} {
      const int n = grid.size();

      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
          int val = grid[i][j];

          dict[val] = {i, j};
          _grid[i+1][j+1] = val;
        }

      for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
          diag[i-1][j-1] = _grid[i-1][j-1] + _grid[i-1][j+1] + _grid[i+1][j-1] + _grid[i+1][j+1];
          adja[i-1][j-1] = _grid[i][j-1] + _grid[i][j+1] + _grid[i+1][j] + _grid[i-1][j];
        }
    }
    
    int adjacentSum(int value) {
      auto [i, j] = dict[value];
      return adja[i][j];
    }
    
    int diagonalSum(int value) {
      auto [i, j] = dict[value];
      return diag[i][j];
    }
};


int main() {
  EXECX(
    CTOR(vector<vector<int>>&),
    &NeighborSum::adjacentSum,
    &NeighborSum::diagonalSum
  );
  return 0;
}
