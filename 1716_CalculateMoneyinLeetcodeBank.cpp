#include "utils3.hpp"

class Solution {
  public:
    int totalMoney(int n) {
      // to 0-index base to simplify modula operation (or alike)
      --n;

      // # of weeks
      int w = n / 7;

      // start from 28, increment by 7 every week
      // (28 + 28 + (w-1) * 7) * w / 2
      int res = (49 + 7 * w) * w / 2;

      // # of remaining days
      int d = n - w * 7 + 1;

      // start from 1, increment by 1 for d days
      // add w * d
      res += (1 + d) * d / 2 + w * d;

      return res;
    }
};


int main() {
  UFUNCS(Solution::totalMoney);
  return 0;
}