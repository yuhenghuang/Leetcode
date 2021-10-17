#include "utils3.hpp"

class Solution {
  public:
    vector<int> findDuplicates(vector<int>& nums) {
      int n = nums.size();
      for (int i=0; i<n; ++i) {
        int idx = nums[i]-1;
        while (nums[i]!=i+1 && nums[idx]!=idx+1) {
          swap(nums[i], nums[idx]);
          idx = nums[i]-1;
        }
      }

      vector<int> res;
      for (int i=0; i<n; ++i)
        if (nums[i]!=i+1)
          res.push_back(nums[i]);
      return res;
    }
};


int main() {
  UFUNCS(Solution::findDuplicates);
  return 0;
}
