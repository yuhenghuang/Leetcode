#include "utils3.hpp"

class Solution {
  public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
      int n = nums.size();
      int m = multipliers.size();

      // length on the front, total length
      // switch rank to optimize memory (put total length in row) for c-array
      int dp[m + 1][m + 1];
      dp[0][0] = 0;
      for (int i = 1; i <= m; ++i) {
        dp[i][i] = dp[i-1][i-1] + nums[i-1] * multipliers[i-1];
        dp[0][i] = dp[0][i-1] + nums[n-i] * multipliers[i-1];
      }


      for (int j = 2; j <= m; ++j)
        for (int i = 1; i < j; ++i) 
          dp[i][j] = max(dp[i][j-1] + nums[n-j+i] * multipliers[j-1], dp[i-1][j-1] + nums[i-1] * multipliers[j-1]);

      int res = INT_MIN;
      for (int i = 0; i <= m; ++i)
        if (dp[i][m] > res)
          res = dp[i][m];

      return res;
    }
};


int main() {
  UFUNCS(Solution::maximumScore);
  return 0;
}