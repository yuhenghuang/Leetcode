#include "utils3.hpp"

class Solution {
  public:
    int numTilings(int n) {
      if (n < 3)
        return n;

      constexpr int mod = 1e9 + 7;

      vector<int> dp(n + 1);
      dp[0] = dp[1] = 1;
      dp[2] = 2;

      // accumulative sum of dp in [0, i - 3];
      int acc = 0;
      for (int i = 3; i <= n; ++i) {
        acc = (acc + dp[i-3]) % mod;
        
        int res = (acc * 2) % mod;
        res = (res + (dp[i-1] + dp[i-2]) % mod) % mod;

        dp[i] = res;
      }

      return dp[n];
    }
};


int main() {
  UFUNCS(Solution::numTilings);
  return 0;
}