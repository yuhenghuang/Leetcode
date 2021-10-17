#include "utils3.hpp"

class Solution {
  public:
    int getSum(int a, int b) {
      // incomplete answer

      int c = 0;

      a += 1000;
      b += 1000;

      int c = 0, bc = 0;
      int shift = 0;
      while (a > 0 || b > 0 || bc > 0) {
        int ba = a & 1;
        int bb = b & 1;

        c ^= (ba ^ bb ^ bc) << shift;
        bc = (ba & bb) | (ba & bc) | (bb & bc);

        a >>= 1;
        b >>= 1;
        ++shift;
      }

      return c + 2000;
    }
};


int main() {
  UFUNCS(Solution::getSum);
  return 0;
}