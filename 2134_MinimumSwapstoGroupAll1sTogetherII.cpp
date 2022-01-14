#include <local_leetcode.hpp>

class Solution {
  public:
    int minSwaps(vector<int>& nums) {
      int n = nums.size();

      int dp[2*n + 1];
      dp[0] = 0;

      for (int i = 0; i < n; ++i)
        dp[i+1] = dp[i] + nums[i];

      // count of 1's
      int l = dp[n];

      for (int i = 0; i < l; ++i)
        dp[i+n+1] = dp[i+n] + nums[i];

      int res = l;
      for (int i = 0; i < n; ++i)
        res = min(res, l - dp[i + l] + dp[i]);

      return res;
    }
};


int main() {
  EXECS(Solution::minSwaps);
  return 0;
}