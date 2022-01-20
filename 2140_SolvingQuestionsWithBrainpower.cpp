#include <local_leetcode.hpp>

class Solution {
  public:
    long long mostPoints(vector<vector<int>>& questions) {
      int n = questions.size();
      long dp[n+1];
      dp[n] = 0;

      for (int i = n - 1; i >= 0; --i) {
        int idx = questions[i][1] + i + 1;

        dp[i] = max(
          dp[i+1],
          questions[i][0] + (idx > n ? 0L : dp[idx])
        );
      }

      return dp[0];
    }
};


int main() {
  EXECS(Solution::mostPoints);
  return 0;
}