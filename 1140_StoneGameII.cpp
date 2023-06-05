#include <local_leetcode.hpp>

class Solution {
  public:
    int stoneGameII(vector<int>& piles) {
      const int n = piles.size();

      int prefix[n + 1];
      prefix[0] = 0;

      // index, M
      int dp[n + 1][n + 1];

      for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + piles[i];

        dp[n][i + 1] = 0;
      }

      for (int i = n - 1; i >= 0; --i) 
        for (int j = 1; j <= n; ++j) {
          // cannot take all remaining stones
          if (i + j * 2 <= n) {
            int res = INT_MIN;
            for (int k = 1; k <= j * 2; ++k)
              res = max(res, prefix[i+k] - prefix[i] - dp[i+k][max(j, k)]);

            dp[i][j] = res;
          }
          else
            dp[i][j] = prefix[n] - prefix[i];
        }

      return (dp[0][1] + prefix[n]) / 2;
    }
};


int main() {
  EXECS(Solution::stoneGameII);
  return 0;
}