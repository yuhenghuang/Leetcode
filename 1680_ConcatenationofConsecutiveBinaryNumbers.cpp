#include <local_leetcode.hpp>

class Solution {
  public:
    int concatenatedBinary(int n) {
      constexpr int64_t mod = 1e9 + 7;

      int digits = 1;
      int threshold = 2;

      int64_t res = 0;
      for (int i = 1; i <= n; ++i) {
        if (i >= threshold) {
          threshold <<= 1;
          ++digits;
        }

        res = (res << digits) ^ i;
        res %= mod;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::concatenatedBinary);
  return 0;
}
