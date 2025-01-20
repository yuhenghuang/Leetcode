#include "utils2.hpp"

class Solution {
  public:
    void nextPermutation(vector<int>& nums) {
      int n = nums.size();
      int i = n-1;

      while (i>0 && nums[i-1]>=nums[i])
        --i;

      int j = i--;
      if (j>0) {
        while (j<n && nums[j]>nums[i])
          ++j;

        swap(nums[i], nums[j-1]);
      }

      reverse(nums.begin()+i+1, nums.end());
    }
};


int main() {
  UFUNC(Solution::nextPermutation);
  return 0;
}