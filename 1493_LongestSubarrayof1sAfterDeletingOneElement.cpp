#include <local_leetcode.hpp>

class Solution {
  public:
    int longestSubarray(vector<int>& nums) {
      const int n = nums.size();

      int res = 0;

      bool zero = false;
      for (int i = 0, j = 0; j < n; ++i) {
        for (; j < n && (nums[j] == 1 || !zero); ++j)
          if (nums[j] == 0)
            zero = true;

        res = max(res, j - i - 1);

        if (nums[i] == 0)
          zero = false;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::longestSubarray);
  return 0;
}