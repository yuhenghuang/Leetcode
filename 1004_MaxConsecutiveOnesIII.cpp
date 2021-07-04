#include "utils2.hpp"

class Solution {
  public:
    int longestOnes(vector<int>& nums, int k) {
      int n = nums.size();

      int res = 0;
      int j = 0;
      for (int i = 0; i < n; ++i) {
        while (j < n && (nums[j] > 0 || k > 0)) {
          if (nums[j++] == 0)
            --k;
        }

        res = max(res, j - i);

        // early stop
        if (j == n)
          break;

        if (nums[i] == 0)
          ++k;
      }

      return res;
    }
};


int main() {
  UFUNC(Solution::longestOnes);
  return 0;
}