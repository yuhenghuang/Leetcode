#include "utils2.hpp"

class Solution {
  public:
    int brokenCalc(int X, int Y) {
      int i = 0;
      while ( (X << i) < Y)
        ++i;

      int res = i;
      int diff = (X << i) - Y;
      while (diff) {
        int mod = 1 << i--;
        res += diff / mod;
        diff %= mod;
      }

      return res;
    }
};


int main() {
  UFUNC(Solution::brokenCalc);
  return 0;
}