#include <local_leetcode.hpp>

class Solution {
  public:
    int countMaxOrSubsets(vector<int>& nums) {
      int n = nums.size();

      int val = 0;
      for (int i = 0; i < n; ++i)
        val |= nums[i];

      int N = 1 << n;
      vector<int> dp(N);

      int res = 0;
      for (int i = 1; i < N; ++i) {
        int j = __builtin_ctz(i);

        dp[i] = dp[i ^ (1 << j)] | nums[j];

        if (dp[i] == val)
          ++res;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::countMaxOrSubsets);
  return 0;
}