#include <local_leetcode.hpp>

class Solution {
  public:
    string stoneGameIII(vector<int>& stoneValue) {
      const int n = stoneValue.size();

      int prefix[n + 3];

      prefix[0] = 0;
      for (int i = 0; i < n; ++i) 
        prefix[i + 1] = prefix[i] + stoneValue[i];
      prefix[n + 2] = prefix[n + 1] = prefix[n];

      int dp[n + 3];
      dp[n + 2] = dp[n + 1] = dp[n] = 0;

      for (int i = n - 1; i >= 0; --i) {
        int res = INT_MIN;

        for (int j = 1; j <= 3; ++j)
          res = max(res, prefix[i + j] - prefix[i] - dp[i + j]);

        dp[i] = res;
      }

      return dp[0] == 0 ? "Tie" : (dp[0] > 0 ? "Alice" : "Bob");
    }
};


int main() {
  EXECS(Solution::stoneGameIII);
  return 0;
}