#include "utils3.hpp"

class Solution {
  public:
    int maximumScore(vector<int>& nums, int k) {
      int n = nums.size();

      int res = 0;

      // current minimum value in [i, j]
      int h = nums[k];

      // left(i) and right(j) boundary of subarray, inclusive
      int i = k, j = k;
      while (true) {
        while (i > 0 && nums[i-1] >= h)
          --i;

        while (j < n-1 && nums[j+1] >= h)
          ++j;

        res = max(res, (j - i + 1) * h);

        // try updating h at either i-1 or j+1 if possible
        if (i == 0 && j == n-1)
          break;
        else if (i > 0 && (j == n - 1 || nums[i-1] >= nums[j+1]))
          h = nums[i-1];
        else
          h = nums[j+1];
      }

      return res;
    }
};


int main() {
  UFUNCS(Solution::maximumScore);
  return 0;
}