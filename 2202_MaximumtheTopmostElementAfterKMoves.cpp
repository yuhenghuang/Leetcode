#include <local_leetcode.hpp>

class Solution {
  public:
    int maximumTop(vector<int>& nums, int k) {
      if (k == 0)
        return nums.front();

      int n = nums.size();

      if (n == 1)
        return k & 1 ? -1 : nums.front();
        
      // n + 1 ops are enough to find the global maximum
      if (k > n)
        k = n + 1;

      // after removing k times
      int res = k < n ? nums[k] : -1;

      // removing k - 1 times and put max num back
      for (int i = 0; i < k - 1; ++i)
        if (nums[i] > res)
          res = nums[i];

      return res;
    }
};


int main() {
  EXECS(Solution::maximumTop);
  return 0;
}