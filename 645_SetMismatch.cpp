#include "utils2.hpp"

class Solution {
  public:
    vector<int> findErrorNums(vector<int>& nums) {
      int n = nums.size();
      
      for (int i=0; i<n; ++i) {
        int j = nums[i] - 1;
        int k = nums[j] - 1;
        while (i != j && j != k) {
          swap(nums[i], nums[j]);
          j = nums[i] - 1;
          k = nums[j] - 1;
        }
      }
      
      for (int i=0; i<n; ++i)
        if (nums[i] != i+1)
          return {nums[i], i+1};
      
      return {-1, -1};
    }
};


int main() {
  UFUNC(Solution::findErrorNums);
  return 0;
}