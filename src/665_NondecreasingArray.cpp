#include "utils2.hpp"

class Solution {
  public:
    bool checkPossibility(vector<int>& nums) {
      int n = nums.size();

      int i = 0;
      while (i < n-1 && nums[i] <= nums[i+1])
        ++i;

      int j = n-1;
      while (j > i && nums[j] >= nums[j-1])
        --j;

      return j <= i + 1 && (
        nums[i] <= nums[j] || 
        i == 0 || (i > 0 && nums[i-1] <= nums[j]) || 
        j == n-1 || (j < n-1 && nums[i] <= nums[j+1])
        );
    }

    bool checkPossibilityOn(vector<int>& nums) {
      int n = nums.size();
      int retry = 1;
      int prev = nums[0];
      for (int i = 1; i < n; ++i) {
        if (prev <= nums[i])
          prev = nums[i];
        else {
          if (retry-- == 0)
            return false;

          if (i < 2 || nums[i] >= nums[i-2])
            prev = nums[i-2];
        }
      }

      return true;
    }
};


int main() {
  {
    UFUNC(Solution::checkPossibility);
  }
  {
    UFUNC(Solution::checkPossibilityOn);
  }
  return 0;
}