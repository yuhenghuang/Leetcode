#include "utils3.hpp"

class Solution {
  public:
    void sortColors(vector<int>& nums) {
      if (nums.empty())
        return;

      int i = 0, j = nums.size() - 1;
      int k = 0;
      while (k <= j) {
        if (nums[k] == 0) 
          swap(nums[k++], nums[i++]);
        else if (nums[k] == 2) 
          swap(nums[k], nums[j--]);
        else
          ++k;
      }
    }
};


int main() {
  UFUNCS(Solution::sortColors);
  return 0;
}