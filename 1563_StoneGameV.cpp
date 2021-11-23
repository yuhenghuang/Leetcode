#include "utils3.hpp"

class Solution {
  public:
    int stoneGameV(vector<int>& stoneValue) {
      int n = stoneValue.size();

      vector<int> prefix(n + 1);
      for (int i = 0; i < n; ++i)
        prefix[i+1] = prefix[i] + stoneValue[i];

      int dp[n][n];
      memset(dp, 0, sizeof(dp));

      // O(n^3)

      // length
      for (int k = 1; k < n; ++k)
        // start index
        for (int i = 0; i + k < n; ++i)
          // [i, j] and [j+1, i+k]
          // the possible choices of j can be limit to O(1) by binary search. -> O(n^2 logn) time complexity
          for (int j = i; j < i + k; ++j) {
            int l = prefix[j+1] - prefix[i];
            int r = prefix[i+k+1] - prefix[j+1];

            if (l < r)
              dp[i][i+k] = max(dp[i][i+k], l + dp[i][j]);
            else if (l > r)
              dp[i][i+k] = max(dp[i][i+k], r + dp[j+1][i+k]);
            else 
              dp[i][i+k] = max(dp[i][i+k], l + max(dp[i][j], dp[j+1][i+k]));
          }

      return dp[0][n-1];
    }
};


int main() {
  UFUNCS(Solution::stoneGameV);
  return 0;
}