#include <local_leetcode.hpp>

class Solution {
  public:
    bool isPowerOfFour(int n) {
      return __builtin_popcount(n) == 1 && !(__builtin_ctz(n) & 1);
    }
};


int main() {
  EXECS(Solution::isPowerOfFour);
  return 0;
}