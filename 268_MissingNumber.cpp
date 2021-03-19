#include "utils2.hpp"

class Solution {
  public:
    int missingNumber(vector<int>& nums) {
      int n = nums.size();
      
      int res = n;
      for (int i=0; i<n; ++i) {
        res ^= i;
        res ^= nums[i];
      }
      
      return res;
    }
};


int main() {
  UFUNC(Solution::missingNumber);
  return 0;
}