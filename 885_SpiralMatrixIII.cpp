#include <local_leetcode.hpp>

class Solution {
  private:
    static constexpr int dirs[4][2] {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int i, int j) {
      int n = rows * cols;

      vector<vector<int>> res;

      res.reserve(n);
      res.push_back({i, j});

      int d = 0; // direction
      int l = 0; // current length of moving forward

      while (n > 1) {
        if ((d & 1) == 0)
          ++l;

        for (int k = 0; k < l; ++k) {
          i += dirs[d][0];
          j += dirs[d][1];

          if (0 <= i && i < rows && 0 <= j && j < cols) {
            res.push_back({i, j});
            --n;
          }
        }

        d = (d + 1) % 4;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::spiralMatrixIII);
  return 0;
}