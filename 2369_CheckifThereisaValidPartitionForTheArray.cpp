#include <local_leetcode.hpp>

class Solution {
  public:
    bool validPartition(vector<int>& nums) {
      const int n = nums.size();

      bool dp[n+1];
      dp[0] = true;
      dp[1] = false;
      dp[2] = nums[0] == nums[1];

      for (int i = 2; i < n; ++i)
        dp[i+1] = (dp[i-1] && nums[i] == nums[i-1]) || (
          dp[i-2] && ((nums[i] == nums[i-1] && nums[i-1] == nums[i-2]) || (nums[i] == nums[i-1] + 1 && nums[i-1] == nums[i-2] + 1))
        );

      return dp[n];
    }
};


int main() {
  EXECS(Solution::validPartition);
  return 0;
}