#include <local_leetcode.hpp>

class Solution {
  public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int res = INT_MAX;

      int sum = 0;
      for (int i = 0, j = 0; j < nums.size(); ++j) {
        sum += nums[j];

        for (; sum - nums[i] >= target; ++i)
          sum -= nums[i];

        if (sum >= target && res > j - i + 1)
          res = j - i + 1;
      }

      return res == INT_MAX ? 0 : res;
    }

    int minSubArrayLenPrefix(int target, vector<int>& nums) {
      const int n = nums.size();

      for (int i = 1; i < n; ++i)
        nums[i] += nums[i-1];

      int res = INT_MAX;

      int prefix = 0;
      for (int i = 0, j = 0; i < n; ++i) {
        j = lower_bound(nums.begin() + j, nums.end(), prefix + target) - nums.begin();

        // early stop
        if (j == n)
          break;

        if (res > j - i + 1)
          res = j - i + 1;

        prefix = nums[i];
      }

      return res == INT_MAX ? 0 : res;
    }
};


int main() {
  EXECS(Solution::minSubArrayLen);
  EXECS(Solution::minSubArrayLenPrefix);
  return 0;
}