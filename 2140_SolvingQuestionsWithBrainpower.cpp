#include <local_leetcode.hpp>

class Solution {
  public:
    long long mostPoints(vector<vector<int>>& questions) {
      int n = questions.size();
      int64_t dp[n+1];
      dp[n] = 0;

      for (int i = n - 1; i >= 0; --i) {
        int j = questions[i][1] + i + 1;

        dp[i] = max(
          dp[i+1],
          questions[i][0] + (j > n ? (int64_t) 0 : dp[j])
        );
      }

      return dp[0];
    }

    long long mostPointsNew(vector<vector<int>>& questions) {
      using ll_t = long long;

      const int n = questions.size();

      ll_t dp[n + 1];
      memset(dp, 0, sizeof(dp));

      for (int i = 0; i < n; ++i) {
        dp[i+1] = max(dp[i+1], dp[i]); // skip questions[i]

        int j = min(i + questions[i][1] + 1, n);
        
        dp[j] = max(dp[j], dp[i] + questions[i][0]);
      }

      return dp[n];
    }
};


int main() {
  EXECS(Solution::mostPoints);
  EXECS(Solution::mostPointsNew);
  return 0;
}