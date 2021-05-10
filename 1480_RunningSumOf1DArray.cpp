#include "utils2.hpp"

class Solution {
  public:
    vector<int> runningSum(vector<int>& nums) {
      for (int i = 1; i < nums.size(); ++i)
        nums[i] += nums[i-1];

      return nums;
    }
};


int main() {
  UFUNC(Solution::runningSum);
  return 0;
}