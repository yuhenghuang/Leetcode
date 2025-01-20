#include "utils2.hpp"

class Solution {
  public:
    int fib(int n) {
      return n < 2 ? n : fib(n-1) + fib(n-2);
    }

    int fibOn(int n) {
      if (n < 2)
        return n;

      int a = 0, b = 1, c;
      for (int i=2; i<=n; ++i) {
        c = a + b;
        a = b;
        b = c;
      }
      return c;
    }
};


int main() {
  {
    UFUNC(Solution::fib);
  }
  {
    UFUNC(Solution::fibOn);
  }
  return 0;
}