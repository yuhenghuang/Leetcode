#include <local_leetcode.hpp>

class Solution {
  public:
    long long zeroFilledSubarray(vector<int>& nums) {
      int64_t res = 0;

      int i = -1;
      for (int j = 0; j < (int) nums.size(); ++j) {
        if (nums[j] != 0)
          i = j;
        else
          res += j - i;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::zeroFilledSubarray);
  return 0;
}