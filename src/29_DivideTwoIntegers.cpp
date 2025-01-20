#include "utils2.hpp"

class Solution {
  public:
    int divide(int dividend, int divisor) {
      if (divisor == 1)
        return dividend;
      else if (dividend == divisor)
        return 1;
      else if (divisor == INT_MIN)
        return 0;
      
      if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;
      
      bool sign = true;
      int res = 0;
      
      if (divisor < 0) {
        divisor = -divisor;
        sign = !sign;
      }
      
      if (dividend == INT_MIN) {
        dividend += divisor;
        ++res;
      }
      
      if (dividend < 0) {
        dividend = -dividend;
        sign = !sign;
      }
      
      int digits = 0;
      while ((divisor << digits) < (1 << 30) && dividend > (divisor << digits))
        digits++;
      
      for (; digits >= 0; --digits) {
        int accDivisor = divisor << digits;
        if (dividend >= accDivisor) {
          dividend -= accDivisor;
          res += 1 << digits;
        }
      }
      
      return sign ? res : -res;
    }
};


int main() {
  UFUNC(Solution::divide);
  return 0;
}