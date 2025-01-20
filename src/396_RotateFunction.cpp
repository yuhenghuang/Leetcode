#include <local_leetcode.hpp>

class Solution {
  public:
    int maxRotateFunction(vector<int>& nums) {
      const int n = nums.size();

      int sum = 0;
      int y = 0;
      for (int i = 0; i < n; ++i) {
        sum += nums[i];
        y += i * nums[i];
      }

      int res = y;
      // index i is the end of rotated array
      for (int i = 0; i < n - 1; ++i) {
        y -= (sum - nums[i]) - nums[i] * (n - 1);

        if (y > res)
          res = y;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::maxRotateFunction);
  return 0;
}