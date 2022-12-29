#include <local_leetcode.hpp>

class Solution {
  private:
    int divide(int n, int d) {
      while (n % d == 0)
        n /= d;

      return n;
    }

  public:
    bool isUgly(int n) {
      if (n < 1)
        return false;

      for (int d : {2, 3, 5})
        n = divide(n, d);

      return n == 1;
    }
};


int main() {
  EXECS(Solution::isUgly);
  return 0;
}