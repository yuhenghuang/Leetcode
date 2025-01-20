#include <local_leetcode.hpp>

class Solution {
  public:
    int minCost(vector<int>& nums, int k) {
      int n = nums.size();

      // no need to split array
      // avoid unnecessary computing of int64_t
      if (k >= n) {
        int8_t seen[n];
        memset(seen, 0, sizeof(seen));

        int res = k;

        for (int num : nums) {
          if (seen[num] > (int8_t) 1)
            ++res;
          else if (seen[num]) {
            ++seen[num];
            res += 2;
          }
          else
            seen[num] = true;
        }

        return res;
      }

      // 3 types of contiditions
      // not seen, seen once, seen multiple times
      int8_t seen[n][n];
      memset(seen, 0, sizeof(seen));

      // importance value of subarray from index to current i
      vector<int> value(n);

      // total value of subarray of first $index chars
      vector<int> dp(n + 1);

      for (int i = 1; i <= n; ++i) {
        int num = nums[i - 1];
        int res = INT_MAX;
        for (int j = 0; j < i; ++j) {
          if (seen[j][num] > static_cast<int8_t>(1))
            ++value[j];
          else if (seen[j][num]) {
            ++seen[j][num];
            value[j] += 2;
          }
          else
            seen[j][num] = true;

          res = min(res, dp[j] + value[j]);
        }
        dp[i] = res + k;
      }

      return dp[n];
    }
};


int main() {
  EXECS(Solution::minCost);
  return 0;
}