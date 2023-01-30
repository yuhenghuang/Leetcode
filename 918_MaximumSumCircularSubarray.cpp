#include <local_leetcode.hpp>

class Solution {
  public:
    int maxSubarraySumCircularWrong(vector<int>& nums) {
      int n = nums.size();

      int res = 0;

      int j = 0;
      int sum = 0;
      for (int i = 0; i < 2 * n; ++i) {
        // one circle
        if (i - j == n)
          break;

        int k = i % n;

        sum += nums[k];

        if (sum > res)
          res = sum;
        else if (sum < 0) {
          if (i >= n - 1)
            break;

          sum = 0;
          j = i + 1;
        }
      }

      return res;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
      int n = nums.size();

      int sum = reduce(nums.begin(), nums.end());

      int res = nums[0];

      int premin = 0;
      int premax = 0;
      int curr = 0;

      // corner case: i == n - 1 and premax over nothing -> curr - premax == sum -> empty subarray
      for (int i = 0; i + 1 < n; ++i) {
        curr += nums[i];

        res = max(
          res,
          max(curr - premin, sum - (curr - premax))
        );

        premin = min(premin, curr);
        premax = max(premax, curr);
      }

      curr += nums[n - 1];

      // no need to compute sum - (curr - premax) when i == n - 1
      // because in this situation, the subarray is NEVER circular
      return max(res, curr - premin);
    }
};


int main() {
  EXECS(Solution::maxSubarraySumCircular);
  return 0;
}