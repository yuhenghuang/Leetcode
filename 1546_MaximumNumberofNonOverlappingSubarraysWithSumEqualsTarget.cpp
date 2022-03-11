#include <local_leetcode.hpp>

class Solution {
  public:
    int maxNonOverlapping(vector<int>& nums, int target) {
      int n = nums.size();

      // prefix sum, index
      unordered_map<int, int> m{{0, -1}};

      // answers over [0, i) of nums
      vector<int> dp(n + 1);

      int prefix = 0;
      for (int i = 0; i < n; ++i) {
        prefix += nums[i];

        auto iter = m.find(prefix - target);

        if (iter == m.end())
          dp[i+1] = dp[i];
        else
          dp[i+1] = max(dp[i], dp[iter->second + 1] + 1);

        m[prefix] = i;
      }

      return dp.back();
    }
};


int main() {
  EXECS(Solution::maxNonOverlapping);
  return 0;
}