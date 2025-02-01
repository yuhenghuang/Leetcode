#include <local_leetcode.hpp>

class Solution {
  public:
    bool isArraySpecial(vector<int>& nums) {
      for (int i = 1; i < (int) nums.size(); ++i)
        if (((nums[i-1] + nums[i]) & 1) ^ 1)
          return false;

      return true;
    }
};


int main() {
  EXECS(Solution::isArraySpecial);
  return 0;
}