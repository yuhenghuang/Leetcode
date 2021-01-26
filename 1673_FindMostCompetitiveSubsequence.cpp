#include "utils.hpp"

class Solution {
  public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
      vector<int> res;
      res.reserve(k);

      int n = nums.size();
      for (int i=0; i<n; ++i) {
        while (res.size()+n-i>k && !res.empty() && res.back() > nums[i])
          res.pop_back();

        if (res.size()<k)
          res.push_back(nums[i]);
      }

      return res;
    }
};


int main() {
  UFUNC(Solution::mostCompetitive);
  return 0;
}