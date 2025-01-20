#include <local_leetcode.hpp>

class Solution {
  public:
    int longestArithSeqLength(vector<int>& nums) {
      int dp[1000][1001];

      const int n = nums.size();
      memset(dp, 0, sizeof(dp[1001]) * n);

      int res = 0;
      for (int i = 1; i < n; ++i)
        for (int j = 0; j < i; ++j) {
          int d = nums[i] - nums[j] + 500;
          dp[i][d] = dp[j][d] + 1;

          res = max(res, dp[i][d]);
        }

      return res + 1;
    }
};


int main() {
  EXECS(Solution::longestArithSeqLength);
  return 0;
}