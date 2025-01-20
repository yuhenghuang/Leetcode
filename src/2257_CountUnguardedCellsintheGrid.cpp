#include <local_leetcode.hpp>

class Solution {
  private:
    enum Cell {
      EMPTY,
      GUARD,
      WALL,
      WATCHED
    };

  public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
      vector<vector<Cell>> grid(m, vector<Cell>(n, EMPTY));

      for (auto& coord : guards)
        grid[coord[0]][coord[1]] = GUARD;

      for (auto& coord : walls)
        grid[coord[0]][coord[1]] = WALL;

      vector<Cell> row(m, EMPTY), col(n, EMPTY);

      for (int j = 0; j < n; ++j) {
        for (int i = 0; i < m; ++i)
          if (grid[i][j] == GUARD) 
            row[i] = GUARD;
          else if (grid[i][j] == WALL)
            row[i] = WALL;
          else {
            if (row[i] == GUARD)
              grid[i][j] = WATCHED;
          }
      }

      row.assign(m, EMPTY);
      for (int j = n - 1; j >= 0; --j) {
        for (int i = 0; i < m; ++i)
          if (grid[i][j] == GUARD) 
            row[i] = GUARD;
          else if (grid[i][j] == WALL)
            row[i] = WALL;
          else {
            if (row[i] == GUARD)
              grid[i][j] = WATCHED;
          }
      }

      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
          if (grid[i][j] == GUARD) 
            col[j] = GUARD;
          else if (grid[i][j] == WALL)
            col[j] = WALL;
          else {
            if (col[j] == GUARD)
              grid[i][j] = WATCHED;
          }
      }

      col.assign(n, EMPTY);
      for (int i = m - 1; i >= 0; --i) {
        for (int j = 0; j < n; ++j)
          if (grid[i][j] == GUARD) 
            col[j] = GUARD;
          else if (grid[i][j] == WALL)
            col[j] = WALL;
          else {
            if (col[j] == GUARD)
              grid[i][j] = WATCHED;
          }
      }

      int res = 0;
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (grid[i][j] == EMPTY)
            ++res;

      return res;
    }
};


int main() {
  EXECS(Solution::countUnguarded);
  return 0;
}