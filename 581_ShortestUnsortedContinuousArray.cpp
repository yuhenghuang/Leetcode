#include "utils2.hpp"

class Solution {
  public:
    int findUnsortedSubarray(vector<int>& nums) {
      int n = nums.size();

      int p = 0;
      int temp = INT_MIN;
      for (int i=0; i<n; ++i) {
        if (nums[i] < temp)
          p = i;
        else
          temp = nums[i];
      }
      
      int q = 1;
      temp = INT_MAX;
      for (int i=n-1; i>=0; --i) {
        if (nums[i] > temp)
            q = i;
        else
          temp = nums[i];
      }
      
      return p - q + 1;
    }
};


int main() {
  UFUNC(Solution::findUnsortedSubarray);
  return 0;
}