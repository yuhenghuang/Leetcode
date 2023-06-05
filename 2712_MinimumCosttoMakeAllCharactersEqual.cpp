#include <local_leetcode.hpp>

class Solution {
  public:
    long long minimumCost(string s) {
      const int n = s.size();

      // (zeros, ones)
      int64_t dp[n + 1][2];
      dp[0][0] = dp[0][1] = 0;

      int j = 0;
      for (int i = 0; i < n; ++i) {
        if (i > 0 && s[i] != s[i-1])
          j = i;

        int k = s[i] - '0';

        dp[i+1][k] = min(dp[j][k], dp[j][1-k] + j);
        dp[i+1][1-k] = min(dp[j][k], dp[j][1-k] + j) + i + 1;
      }

      int64_t res = min(dp[n][0], dp[n][1]);

      dp[n][0] = dp[n][1] = 0;

      j = n;
      for (int i = n - 1; i >= 0; --i) {
        if (i + 1 < n && s[i] != s[i+1])
          j = i + 1;

        int k = s[i] - '0';

        int64_t same = min(dp[j][k], dp[j][1-k] + n - j);
        int64_t oppo = min(dp[j][k], dp[j][1-k] + n - j) + n - i;

        res = min(res, min(dp[i][k] + same, dp[i][1-k] + oppo));

        dp[i][k] = same;
        dp[i][1-k] = oppo;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::minimumCost);
  return 0;
}