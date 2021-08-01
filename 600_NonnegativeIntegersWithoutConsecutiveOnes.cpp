#include "utils3.hpp"

class Solution {
  public:
    int findIntegers(int n) {

      int b = 2;
      while ((1 << b) <= n)
        ++b;

      // count of integers start with '0'
      vector<int> dp(b);

      dp[0] = 1;
      dp[1] = 2;
      for (int i = 2; i < b; ++i)
        // '0' and dp[i-1], '01' and dp[i-2]
        dp[i] = dp[i-1] + dp[i-2];

      int res = 0;
      for (int i = b - 1; i >= 0; --i) {
        // if bit at i is 1
        if ((1 << i) & n) {
          // safely count in all integers with bit at i = 0
          res += dp[i];

          // move forward as if bit at i is kept to be 1
          // if there are two consecutive 1 that violates the condition
          if ((1 << (i + 1)) & n)
            break;
        }

        // count n itself
        if (i == 0)
          ++res;
      }

      return res;
    }
};

class Foo {
  public:
    int val;
};


int main() {
  UFUNCS(Solution::findIntegers);
  return 0;
}