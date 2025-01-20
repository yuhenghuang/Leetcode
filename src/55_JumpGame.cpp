#include <local_leetcode.hpp>

class Solution {
  public:
    bool canJump(vector<int>& nums) {
      int j = 0; // max index of next step
      for (int i = 0; i < (int) nums.size(); ++i)
        if (i > j)
          return false;
        else
          j = max(j, i + nums[i]);

      return true;
    }
};


int main() {
  EXECS(Solution::canJump);
  return 0;
}