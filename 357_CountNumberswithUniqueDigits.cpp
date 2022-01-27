#include <local_leetcode.hpp>

class Solution {
  private:
    // 0 ~ 10
    static int factorial[11];

  public:
    int countNumbersWithUniqueDigits(int n) {
      int res = 0;
      for (int i = 0; i < 1024; ++i) {
        int b = __builtin_popcount(i);
        if (b <= n) 
          res += (i & 1) ? factorial[b] - factorial[b-1] : factorial[b];
      }

      return res;
    }
};

int Solution::factorial[11] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 362880};


int main() {
  EXECS(Solution::countNumbersWithUniqueDigits);
  return 0;
}