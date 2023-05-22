#include <local_leetcode.hpp>

class Solution {
  public:
    int countGoodStrings(const int low, const int high, const int zero, const int one) {
      constexpr int mod = 1e9 + 7;

      vector<int> dp(high + 1);
      dp[0] = 1;
      for (int i = 0; i + min(zero, one) <= high; ++i) {
        if (i + zero <= high)
          dp[i + zero] = (dp[i] + dp[i + zero]) % mod;

        if (i + one <= high)
          dp[i + one] = (dp[i] + dp[i + one]) % mod;
      }

      int res = 0;
      for (int i = low; i <= high; ++i)
        if ((res += dp[i]) >= mod)
          res -= mod;

      return res;
    }
};


int main() {
  EXECS(Solution::countGoodStrings);
  return 0;
}