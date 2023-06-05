#include <local_leetcode.hpp>

class Solution {
  public:
    long long maxStrength(vector<int>& nums) {
      const int n = nums.size();
      const int N = 1 << n;

      int64_t dp[N];
      dp[0] = 1;

      int64_t res = INT64_MIN;
      for (int b = 1; b < N; ++b) {
        int i = __builtin_ctz(b);
        dp[b] = nums[i] * dp[b ^ (1 << i)];
        
        if (dp[b] > res)
          res = dp[b];
      }

      return res;
    }
};


int main() {
  EXECS(Solution::maxStrength);
  return 0;
}