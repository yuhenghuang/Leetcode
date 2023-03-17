#include <local_leetcode.hpp>

class Solution {
  public:
    int singleNonDuplicate(vector<int>& nums) {
      int l = 0, r = (int) nums.size() - 1;

      while (l < r) {
        int m = l + (r - l) / 2;

        if (m & 1)
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
  EXECS(Solution::singleNonDuplicate);
  return 0;
}