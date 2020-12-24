#include "utils.hpp"

class Solution {
  public:
    bool increasingTriplet(vector<int>& nums) {
      int n = nums.size();
      vector<int> right_max(n);

      int r = INT_MIN;
      for (int i=n-1; i>1; --i) {
        r = max(r, nums[i]);
        right_max[i] = r;
      }

      int l = INT_MAX;
      for (int i=1; i<n-1; ++i) {
        l = min(l, nums[i-1]);
        if (l<nums[i] && nums[i]<right_max[i+1])
          return true;
      }

      return false;
    }
};


int main() {
  UFUNC(Solution::increasingTriplet);
  return 0;
}