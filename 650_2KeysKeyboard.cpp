#include "utils3.hpp"

class Solution {
  public:
    int minSteps(int n) {
      // # of A, # to be pasted
      vector<vector<int>> dp(n+1);

      // initialize dp
      dp[1].push_back(0);
      for (int i = 2; i <= n; ++i) {
        dp[i].assign(i / 2 + 1, INT_MAX);}

      for (int i = 1; i < n; ++i)
        for (int j = 0; j < i / 2 + 1; ++j)
          if (dp[i][j] < INT_MAX) {
            // paste
            if (i + j <= n)
              dp[i+j][j] = min(dp[i+j][j], dp[i][j] + 1);

            // copy and paste
            if (i * 2 <= n)
              dp[i*2][i] = min(dp[i*2][i], dp[i][j] + 2);
          }

      return *min_element(dp[n].begin(), dp[n].end());
    }
};


int main() {
  UFUNCS(Solution::minSteps);
  return 0;
}