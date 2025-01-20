#include <local_leetcode.hpp>

class Solution {
  public:
    int triangularSum(vector<int>& nums) {
      // O(n^2)

      for (int i = static_cast<int>(nums.size()) - 1; i > 0; --i)
        for (int j = 0; j < i; ++j)
          nums[j] = (nums[j] + nums[j+1]) % 10;

      return nums[0] % 10;
    }

    int triangularSumOn(vector<int>& nums) {
      // O(n)
      // need modular multiplicative inverse to avoid overflow
      // incomplete

      int n = static_cast<int>(nums.size()) - 1;

      int res = 0;


      return res;
    }
};


int main() {
  EXECS(Solution::triangularSum);
  return 0;
}