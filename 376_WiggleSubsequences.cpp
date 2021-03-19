#include "utils2.hpp"

class Solution {
  public:
    int wiggleMaxLength(vector<int>& nums) {
      int n = nums.size();
      int i = 0, j;
      
      int res = 1;
      while (i < n-1) {
        j = i;
        while (j < n-1 && nums[j] <= nums[j+1])
          ++j;
        
        if (i < j && nums[i] < nums[j])
          ++res;
        
        i = j;
        while (j < n-1 && nums[j] >= nums[j+1])
          ++j;
        
        if (i < j && nums[i] > nums[j])
          ++res;
        
        i = j;
      }
      
      return res;
    }
};


int main() {
  UFUNC(Solution::wiggleMaxLength);
  return 0;
}