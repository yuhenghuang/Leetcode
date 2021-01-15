#include "utils.hpp"

class Solution {
  public:
    int minOperations(vector<int>& nums, int x) {
      int n = nums.size();

      int i = 0;
      int sum = 0;
      while (i<n && sum<x) 
        sum += nums[i++];

      int res = INT_MAX;
      int j = n-1;
      for (--i; i>=-1; --i) {
        while (j>i && sum<x)
          sum += nums[j--];

        if (sum==x)
          res = min(res, i+n-j);

        if (i>=0)
          sum -= nums[i];
      }

      return res==INT_MAX ? -1 : res;
    }
};


int main() {
  UFUNC(Solution::minOperations);
  return 0;
}