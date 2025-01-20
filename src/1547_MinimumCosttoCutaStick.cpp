#include <local_leetcode.hpp>

class Solution {
  public:
    int minCost(int n, vector<int>& cuts) {
      cuts.push_back(0);
      sort(cuts.begin(), cuts.end());
      cuts.push_back(n);

      const int m = cuts.size();

      // [i, j]
      int dp[102][102];

      for (int i = 1; i < m; ++i)
        dp[i-1][i] = 0;

      for (int k = 2; k < m; ++k) // k + 1 == length of window
        for (int i = 0; i + k < m; ++i) { // start index of window
          int res = INT_MAX;

          for (int j = i + 1; j < i + k; ++j)
            res = min(res, dp[i][j] + dp[j][i+k]);

          dp[i][i+k] = res + cuts[i+k] - cuts[i];
        }

      return dp[0][m-1];
    }
};


int main() {
  EXECS(Solution::minCost);
  return 0;
}