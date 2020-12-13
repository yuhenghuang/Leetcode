#include "utils.hpp"

class Solution {
  public:
    int removeDuplicates(vector<int>& nums) {
      int n = nums.size();
      int res = 0;

      int count;
      int i=0, l=0, r=0;
      while (l<n) {
        while (r<n && nums[r]==nums[l])
          ++r;

        count = min(2, r-l);
        res += count;
        while (count--)
          nums[i++] = nums[r-1];

        l = r;
      }

      return res;
    }

    void removeDuplicatesInplace(vector<int>& nums) {
      size_t n = removeDuplicates(nums);
      while (nums.size()>n)
        nums.pop_back();
    }
};


int main() {
  {
    UFUNC(Solution::removeDuplicates);
  }
  {
    UFUNC(Solution::removeDuplicatesInplace);
  }
  return 0; 
}