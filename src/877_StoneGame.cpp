#include "utils3.hpp"

class Solution {
  public:
    bool stoneGame(vector<int>& piles) {
      int n = piles.size();
      vector<vector<int>> dp(n, vector<int>(n));

      for (int i = 0; i < n; ++i)
        dp[i][i] = piles[i];

      for (int k = 1; k < n; ++k)
        for (int i = 0; i + k < n; ++i)
          dp[i][i+k] = max(piles[i] - dp[i+1][i+k], piles[i+k] - dp[i][i+k-1]);

      return dp[0][n-1] > 0;
    }
};


int main() {
  UFUNCS(Solution::stoneGame);
  return 0;
}