#include <local_leetcode.hpp>

class Solution {
  public:
    int search(vector<int>& nums, int target) {
      int l = 0, r = nums.size() - 1;
      while (l <= r) {
        int m = l + (r - l) / 2;

        if (nums[m] == target)
          return m;
        else if (nums[0] <= target) {
          if (target < nums[m] || nums[0] > nums[m])
            r = m - 1;
          else
            l = m + 1;
        }
        else {
          if (nums[m] < target || nums[0] <= nums[m])
            l = m + 1;
          else
            r = m - 1;
        }
      }

      return -1;
    }
};


int main() {
  EXECS(Solution::search);
  return 0;
}