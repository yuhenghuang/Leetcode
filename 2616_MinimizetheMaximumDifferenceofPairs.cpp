#include <local_leetcode.hpp>

class Solution {
  public:
    int minimizeMax(vector<int>& nums, int p) {
      const int n = nums.size();

      int dp[n + 1]; // can be optimized out somehow
      dp[0] = dp[1] = 0;

      sort(nums.begin(), nums.end());

      int l = 0, r = nums.back() - nums.front();
      while (l <= r) {
        int m = l + (r - l) / 2;

        for (int i = 1; i < n; ++i)
          dp[i + 1] = (nums[i] - nums[i-1] <= m) ? 1 + dp[i - 1]: dp[i];

        if (dp[n] < p)
          l = m + 1;
        else
          r = m - 1;
      }

      return l;
    }
};


int main() {
  EXECS(Solution::minimizeMax);
  return 0;
}