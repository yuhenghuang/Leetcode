#include <local_leetcode.hpp>

class Solution {
  public:
    long long coloredCellsWrong(int n) {
      /*
        1 -> 1
        2 -> 1 + 4 = (0 * 2 + 1) ^ 2 + 4
        3 -> 9 + 4 = (1 * 2 + 1) ^ 2 + 4
        4 -> 25 + 4 = (2 * 2 + 1) ^ 2 + 4
        ...
      */

      if (n < 2)
        return 1;

      long long h = (n - 2) * 2 + 1;
      return h * h + 4;
    }

    long long coloredCells(long long n) {
      /*
        large square - two small rectangles

        (n * 2 - 1) ^ 2 - n * (n - 1) * 2
        = 4 * n ^ 2 - 4n + 1 - 2 * n ^ 2 + 2n
        = 2 * n ^ 2 - 2n + 1
        = (n - 1) ^ 2 + n ^ 2
      */

      return 2 * n * n - 2 * n + 1;
    }
};


int main() {
  EXECS(Solution::coloredCells);
  return 0;
}