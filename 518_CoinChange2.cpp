#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

static int emm = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

class Solution {
  public:
    int change(int amount, vector<int>& coins) {
      if (amount==0) return 1;
      int N = coins.size();
      sort(coins.begin(), coins.end());
      vector<vector<int>> dp(amount, vector<int>(N, 0));

      for (int i=0; i<amount; ++i)
        for (int j=0; j<N; ++j) {
          int prev = i-coins[j];
          if (prev<-1) 
            break;
          else if (prev>-1) 
            for (int k=0; k<=j; ++k) 
              dp[i][j] += dp[prev][k];
          else
            dp[i][j] = 1;
        }

      int res=0;
      for (int i=0; i<N; ++i)
        res += dp[amount-1][i];
      return res;
    }
};