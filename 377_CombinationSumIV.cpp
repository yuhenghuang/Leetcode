#include <unordered_set>
#include "utils2.hpp"

class Solution {
  public:
    int combinationSum4(vector<int>& nums, int target) {
      sort(nums.begin(), nums.end());

      constexpr long mod = INT_MAX;
      vector<long> dp(target+1, 0);
      dp[0] = 1;
      for (int i = 1; i <= target; ++i)
        for (int k = 0; k < nums.size() && nums[k] <= i; ++k) {
          int j = i - nums[k];
          if (dp[i] + dp[j] > mod) {
            dp[i] = 0;
            break;
          }
          dp[i] += dp[j];
        }
      
      return dp[target];
    }
};


int main() {
  UFUNC(Solution::combinationSum4);
  return 0;
}