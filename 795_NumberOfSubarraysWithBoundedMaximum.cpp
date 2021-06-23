#include "utils2.hpp"

class Solution {
  public:
    int numSubarrayBoundedMaxFor(vector<int>& nums, int left, int right) {
      int n = nums.size();

      int res = 0;

      int lb = -1; // left bound (exclusive)
      int peak = -1; // nearest peak (btw $left and $right, inclusive)
      for (int i = 0; i < n; ++i) {
        int num = nums[i];
        if (num > right) {
          peak = i;
          lb = i;
        }
        else {
          if (left <= num && num <= right)
            peak = i;

          res += peak - lb;
        }
      }

      return res;
    }

    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
      int n = nums.size();

      int res = 0;

      int i = 0;
      while (i < n) {
        // leftmost index non-greater than right
        while (i < n && nums[i] > right)
          ++i;

        int j = i; 
        int k = i - 1; // max value index
        while (j < n && nums[j] <= right) {
          if (nums[j] >= left)
            k = j;

          res += k - i + 1;

          ++j;
        }

        i = j + 1;
      }

      return res;
    }
};


int main() {
  {
    UFUNC(Solution::numSubarrayBoundedMax);
  }
  {
    UFUNC(Solution::numSubarrayBoundedMaxFor);
  }
  return 0;
}