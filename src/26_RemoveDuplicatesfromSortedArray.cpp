#include <local_leetcode.hpp>

class Solution {
  public:
    int removeDuplicates(vector<int>& nums) {
      if (nums.empty()) return 0;
      int p = 0;
      for (int q = 1; q < (int) nums.size(); ++q) 
        if (nums[p] != nums[q]) 
          nums[++p] = nums[q];
      return p + 1;
    }

    vector<int> removeDuplicatesVec(vector<int>& nums) {
      return vector<int>(nums.begin(), nums.begin() + removeDuplicates(nums));
    }
};


int main() {
  EXECS(Solution::removeDuplicatesVec);
  return 0;
}