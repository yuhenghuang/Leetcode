#include <local_leetcode.hpp>

class Solution {
  public:
    int countHillValley(vector<int>& nums) {
      const int n = nums.size();

      int res = 0;

      for (int i = 0, j; i + 1 < n; i = j) {
        j = i;
        for (; j + 1 < n and nums[j] <= nums[j+1]; ++j);

        if (j > i) {
          if (nums[j] > nums[i])
            ++res;

          i = j;
        }

        for (; j + 1 < n and nums[j] >= nums[j+1]; ++j);

        if (nums[j] < nums[i])
          ++res;
      }

      return max(res - 1, 0);
    }
};


int main() {
  EXECS(Solution::countHillValley);
  return 0;
}