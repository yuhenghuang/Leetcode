#include <local_leetcode.hpp>

class Solution {
  public:
    int numRollsToTarget(int n, int k, int target) {
      // O(n * k * target)

      constexpr int mod = 1e9 + 7;

      int temp[1001];
      int dp[1001];

      memset(dp, 0, sizeof(int) * (target + 1));
      dp[0] = 1;

      for (int p = 0; p < n; ++p) {
        memset(temp, 0, sizeof(int) * (target + 1));
        for (int i = 0; i <= target; ++i)
          if (dp[i] > 0)
            for (int j = 1; j <= k && i + j <= target; ++j)
                temp[i + j] = (dp[i] + temp[i + j]) % mod;

        swap(dp, temp);
      }

      return dp[target];
    }
};


int main() {
  EXECS(Solution::numRollsToTarget);
  return 0;
}
