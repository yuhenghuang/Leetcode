#include "utils3.hpp"

class Solution {
  public:
    vector<int> singleNumber(vector<int>& nums) {
      int mask = 0;
      for (int num : nums)
        mask ^= num;

      // find different bit
      int diff = mask & (~mask + 1);

      int x = 0;
      for (int num : nums)
        if ((num & diff) > 0)
          x ^= num;

      return {x, x ^ mask};
    }
};


int main() {
  UFUNCS(Solution::singleNumber);
  return 0;
}