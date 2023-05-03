#include <local_leetcode.hpp>

class Solution {
  public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
      constexpr int mod = 1e9 + 7;

      // member, profit
      int dp[101][101];

      // only need to initialize first n + 1 rows
      memset(dp, 0, sizeof(int[101]) * (n + 1));

      // 1 way to achieve 0 profit with 0 member
      dp[0][0] = 1;
      for (int i = 0; i < (int) group.size(); ++i) {
        int g = group[i];
        int p = profit[i];

        for (int j = n - g; j >= 0; --j)
          for (int k = minProfit; k >= 0; --k) {
            int& res = dp[j + g][min(minProfit, k + p)];
            res += dp[j][k];

            if (res > mod)
              res -= mod;
          }
      }

      int res = 0;
      for (int j = 0; j <= n; ++j) {
        res += dp[j][minProfit];

        if (res > mod)
          res -= mod;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::profitableSchemes);
  return 0;
}