#include "utils2.hpp"

class Solution {
  public:
    int maxProfit(vector<int>& prices, int fee) {
      int n = prices.size();
      
      if (n==0)
        return 0;
      
      vector<vector<int>> dp(2, vector<int>(n, 0));
      dp[1][0] = -prices[0];
      
      for (int i=1; i<n; ++i) {
        dp[1][i] = max(dp[1][i-1], dp[0][i-1] - prices[i]);
        dp[0][i] = max(dp[0][i-1], prices[i] + dp[1][i-1] - fee);
      }
      
      return dp[0][n-1];
    }
};


int main() {
  UFUNC(Solution::maxProfit);
  return 0;
}