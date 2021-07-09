#include "utils2.hpp"


class Solution {
  public:
    int lengthOfLIS(vector<int>& nums) {
      int res = 0;

      auto i = nums.begin();
      auto j = i;
      for (int num : nums) {
        auto m = lower_bound(i, j, num);

        *m = num;

        // enlarge the subarray located in head if $num$ is larger than any number in it
        if (m == j) {
          ++res;
          ++j;
        }
      }

      return res;
    }
};


int main() {
  UFUNC(Solution::lengthOfLIS);
  return 0;
}