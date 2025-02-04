#include <local_leetcode.hpp>

class Solution {
  public:
    int maxAscendingSum(vector<int>& nums) {
      int res = nums.front();
      int curr = res;

      for (int i = 1; i < (int) nums.size(); ++i) {
        if (nums[i] > nums[i-1])
          curr += nums[i];
        else
          curr = nums[i];

        if (curr > res)
          res = curr;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::maxAscendingSum);
  return 0;
}