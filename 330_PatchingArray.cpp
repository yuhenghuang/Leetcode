#include "utils3.hpp"

class Solution {
  public:
    int minPatches(vector<int>& nums, int n) {
      int res = 0;

      auto iter = nums.begin();
      int rem = n;
      // avoid overflow
      while (rem > 0) {
        bool flag = true;
        // num can only increment if it's not greater than the height reached
        while (iter != nums.end() && *iter <= (n - rem + 1)) {
          rem -= *iter++;
          flag = false;
        }

        // no num in nums is usable
        // increment at max step
        if (flag) {
          rem -= n - rem + 1;
          ++res;
        }
      }

      return res;
    }
};


int main() {
  UFUNCS(Solution::minPatches);
  return 0;
}