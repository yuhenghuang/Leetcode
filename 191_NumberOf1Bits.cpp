#include "utils2.hpp"

class Solution {
  public:
    int hammingWeight(uint32_t n) {
      int res = 0;
      while (n > 0) {
        // n & (n-1) to remove rightmost 1
        res += n & 1;
        n >>= 1;
      }

      return res;
    }
};


int main() {
  UFUNC(Solution::hammingWeight);
  return 0;
}