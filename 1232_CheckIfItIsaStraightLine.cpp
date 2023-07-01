#include <local_leetcode.hpp>

class Solution {
  public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
      // ax - by = c
      // a(x1 - x2) = b(y1 - y2)
      // a and b can be any numbers that satisfy the equation above
      // thus we can choose arbitrary a and b
      // to simplify the problem, let
      // a = y1 - y2, b = x1 - x2
      // then given an arbitrary point (x1, y1)
      // c = ax1 - by1

      const int n = coordinates.size();

      if (n < 3)
        return true;

      int a = coordinates[1][1] - coordinates[0][1];
      int b = coordinates[1][0] - coordinates[0][0];
      int c = a * coordinates[0][0] - b * coordinates[0][1];

      for (int i = 2; i < n; ++i)
        if (a * coordinates[i][0] - b * coordinates[i][1] != c)
          return false;

      return true;
    }
};


int main() {
  EXECS(Solution::checkStraightLine);
  return 0;
}