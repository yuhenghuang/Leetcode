#include <local_leetcode.hpp>

class Solution {
  public:
    int findDuplicate(vector<int>& nums) {
      int slow=nums[0], fast=nums[0];
      do {
        slow = nums[slow];
        fast = nums[nums[fast]];
      } while (slow!=fast);

      slow = nums[0];
      while (slow!=fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];
      }
      return fast;
    }

    int findDuplicateBit(vector<int>& nums) {
      // wrong answer
      const int n = nums.size();

      int res = n;
      for (int i = 0; i < n; ++i)
        res ^= nums[i] ^ (i + 1);

      return res;
    }
};

int main() {
  /*
  Solution sol;
  vector<int> nums = {2,1,2};
  cout << sol.findDuplicate(nums) << endl;
  */

  EXECS(Solution::findDuplicate);
  EXECS(Solution::findDuplicateBit);
  return 0;
}