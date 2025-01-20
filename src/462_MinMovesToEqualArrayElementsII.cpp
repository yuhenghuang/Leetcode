#include "utils2.hpp"

class Solution {
  public:
    int minMoves2(vector<int>& nums) {
      // L1 norm -> median
      sort(nums.begin(), nums.end());
      int median = nums[nums.size() / 2];

      int res = 0;
      for (int num : nums)
        res += abs(num - median);

      return res;
    }
};


int main() {
  UFUNC(Solution::minMoves2);
  return 0;
}