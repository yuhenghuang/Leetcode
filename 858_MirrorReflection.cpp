#include "utils.hpp"

class Solution {
  private:
    int compute_gcd(int a, int b) {
      while (a!=b) {
        if (a>b)
          a -= b;
        else
          b -= a;
      }
      return a;
    }
  public:
    int mirrorReflection(int p, int q) {
      int gcd = compute_gcd(p, q);
      int x = q / gcd, y = p / gcd;
      return x%2 + (y+1)%2;
    }
};


int main() {
  UFUNC(Solution::mirrorReflection);
  return 0;
}