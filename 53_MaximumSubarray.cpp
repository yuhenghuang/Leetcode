#include "utils3.hpp"

class Solution {
  private:
    // mid point in the target array
    int dv(vector<int>& nums, int l, int r, int m) {
      // at least one number on each size
      
      int sum = 0;
      int left = INT_MIN;
      for (int i = m; i >= l; --i) {
        sum += nums[i];
        if (sum > left)
          left = sum;
      }

      sum = 0;
      int right = INT_MIN;
      for (int i = m+1; i <= r; ++i) {
        sum += nums[i];
        if (sum > right)
          right = sum;
      }

      return left + right;
    }

    int dv(vector<int>& nums, int l, int r) {
      if (l == r)
        return nums[l];

      int m = l + (r - l) / 2;
      return max(
        max(dv(nums, l, m), dv(nums, m+1, r)),
        dv(nums, l, r, m)
      );
    }

  public:
    int maxSubArray(vector<int>& nums) {
      int prefix = 0;
      int sum = 0;

      int res = INT_MIN;
      int pre = 0;

      for (int num : nums) {
        sum += num;

        res = max(res, sum - pre);

        prefix += num;

        if (pre > prefix)
          pre = prefix;
      }

      return res;
    }

    int maxSubArrayDivideConqure(vector<int>& nums) {
      return dv(nums, 0, (int) nums.size() - 1);
    }
};


int main() {
  UFUNCS(Solution::maxSubArray);
  UFUNCS(Solution::maxSubArrayDivideConqure);
  return 0;
}