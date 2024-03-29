#include <local_leetcode.hpp>

class Solution {
  public:
    bool makesquare(vector<int>& matchsticks) {
      int64_t totalLength = reduce(matchsticks.begin(), matchsticks.end(), int64_t(0));

      if (totalLength % 4 != 0)
        return false;

      int n = matchsticks.size();
      int N = 1 << n;

      int target = totalLength / 4;
      
      vector<int> dp(N, INT_MAX);
      dp[0] = 0;
      for (int i = 0; i < N; ++i) {
        if (dp[i] > target) // skip if dp[i] exceeds the length of a side (target)
          continue;
        else if (dp[i] == target) // reduce dp[i] to 0 if equal to the target
          dp[i] = 0;
        
        for (int j = 0; j < n; ++j)
          if ((i & (1 << j)) == 0) {
            int k = i ^ (1 << j);
            dp[k] = min(dp[k], dp[i] + matchsticks[j]);
          }
      }

      return dp[N-1] == 0;
    }
};


int main() {
  EXECS(Solution::makesquare);
  return 0;
}