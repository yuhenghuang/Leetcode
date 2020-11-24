#include "utils.hpp"

class Solution {
  public:
    bool search(vector<int>& nums, int target) {
      int l = 0, r = nums.size()-1;
      while (l<=r) {
        int m = l + (r-l)/2;

        if (nums[m]==target)
          return true;

        if (nums[m]==nums[l]) {
          ++l;
          continue;
        }

        if ((nums[m] >= nums[l]) ^ (target >= nums[l])) {
          if (nums[m] >= nums[l])
            l = m+1;
          else
            r = m-1;
        }
        else {
          if (nums[m] < target)
            l = m+1;
          else
            r = m-1;
        }
      }

      return false;
    }

    bool searchME(vector<int>& nums, int target) {
      int n = nums.size();
      if (n<1)
        return false;
      else if (nums[0]==target)
        return true;

      int l=0, r=n-1;
      while (l<n-1 && nums[l]==nums[l+1])
        ++l;

      while (l<=r) {
        int m = l + (r-l)/2;

        if (nums[m]==target)
          return true;

        bool m_in_left = nums[m] >= nums[l];
        bool t_in_left = target >= nums[l];
        if (m_in_left ^ t_in_left) {
          if (m_in_left)
            l = m+1;
          else
            r = m-1;
        }
        else {
          if (nums[m] < target)
            l = m+1;
          else
            r = m-1;
        }
      }

      return false;
    }
};


int main() {
  {
    UFUNC(Solution::search);
  }
  {
    UFUNC(Solution::searchME);
  }
  return 0;
}