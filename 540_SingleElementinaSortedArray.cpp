#include "utils3.hpp"

class Solution {
  public:
    int singleNonDuplicate(vector<int>& nums) {
      int l = 0, r = nums.size() - 1;

      while (l < r) {
        int m = l + (r - l) / 2;

        if ((m & 1) > 0)
          --m;

        if (nums[m] == nums[m+1])
          l = m + 2;
        else if (m > 0 && nums[m] == nums[m-1])
          r = m - 2;
        else
          return nums[m];
      }

      return nums[l];
    }
};


int main() {
  UFUNCS(Solution::singleNonDuplicate);
  return 0;
}