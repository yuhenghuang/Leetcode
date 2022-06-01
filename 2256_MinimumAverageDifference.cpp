#include <local_leetcode.hpp>

class Solution {
  public:
    int minimumAverageDifference(vector<int>& nums) {
      const int n = nums.size();

      int64_t sum = reduce(nums.begin(), nums.end(), int64_t());

      int64_t l = 0, r = sum;

      int64_t cap = INT64_MAX;
      int res = -1;

      for (int i = 0; i + 1 < n; ++i) {
        l += nums[i];
        r -= nums[i];

        int64_t temp = abs(l / (i + 1) - r / (n - i - 1));
        if (temp < cap) {
          cap = temp;
          res = i;
        }
      }

      if (sum / n < cap)
        res = n - 1;

      return res;
    }
};


int main() {
  EXECS(Solution::minimumAverageDifference);
  return 0;
}