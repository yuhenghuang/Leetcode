#include <local_leetcode.hpp>

class Solution {
  public:
    int maximumCount(vector<int>& nums) {
      auto l = lower_bound(nums.begin(), nums.end(), 0);
      auto r = upper_bound(nums.begin(), nums.end(), 0);

      return max(l - nums.begin(), nums.end() - r);
    }
};


int main() {
  EXECS(Solution::maximumCount);
  return 0;
}