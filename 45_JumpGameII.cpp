#include "utils2.hpp"

class Solution {
  public:
    int jump(vector<int>& nums) {
      int n = nums.size();
      
      int res = 0;

      // i -- j is reachable in $res$ steps
      // j+1 -- k is reachable in $res$ + 1 steps
      int j = 0, k = 0;
      for (int i = 0; i < n; ++i) {
        if (i > j) {
          j = k;
          ++res;
        }
        
        k = max(k, i + nums[i]);
      }
      
      return res;
    }
};


int main() {
  UFUNC(Solution::jump);
  return 0;
}