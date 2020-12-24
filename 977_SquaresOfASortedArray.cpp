#include "utils.hpp"
#include <algorithm>

class Solution {
  private:
    int square(int num) {
      return num * num;
    }
  public:
    vector<int> sortedSquares(vector<int>& nums) {
      const size_t n = nums.size();
      vector<int> res;
      res.reserve(n);

      auto iter = lower_bound(nums.begin(), nums.end(), 0);

      int l, r;
      r = iter-nums.begin();
      l = r-1;

      while (res.size()<n) {
        if (l<0 || (r<n && nums[l]+nums[r]<0)) 
          res.push_back(square(nums[r++]));
        else
          res.push_back(square(nums[l--]));
      }

      return res;
    }
};


int main() {
  UFUNC(Solution::sortedSquares);
  return 0;
}