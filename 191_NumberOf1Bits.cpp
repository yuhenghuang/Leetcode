#include <local_leetcode.hpp>

class Solution {
  public:
    int hammingWeight(uint32_t n) {
      // return __builtin_popcount(n);

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
  EXECS(Solution::hammingWeight);
  return 0;
}