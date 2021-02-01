#include "utils2.hpp"

class Solution {
  public:
    int concatenatedBinary(int n) {
      static constexpr long mod = 1e9 + 7;

      int digits = 1;
      int threshold = 2;

      long res = 0;
      for (int i=1; i<=n; ++i) {
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
  UFUNC(Solution::concatenatedBinary);
  return 0;
}