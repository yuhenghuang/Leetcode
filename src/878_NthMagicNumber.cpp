#include "utils3.hpp"

class Solution {
  private:
    int gcd(int a, int b) {
      if (b == 0)
        return a;

      return gcd(b, a % b);
    }

  public:
    int nthMagicalNumber(int n, int a, int b) {
      constexpr long mod = 1e9 + 7;

      if (a > b)
        swap(a, b);

      int lcm = a / gcd(a, b) * b;

      long l = 1;
      long r = (long) a * n;
      long m = 0;

      while (l <= r) {
        m = l + (r - l) / 2;

        int cnt = m / a + m / b - m / lcm;
        if (cnt < n)
          l = m + 1;
        else if (cnt > n)
          r = m - 1;
        else
          break;
      }

      return max((m/a)*a, (m/b)*b) % mod;
    }
};


int main() {
  UFUNCS(Solution::nthMagicalNumber);
  return 0;
}