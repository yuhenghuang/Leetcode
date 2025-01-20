#include <local_leetcode.hpp>

class Solution {
  public:
    int reductionOperations(vector<int>& nums) {
      sort(nums.begin(), nums.end(), greater<int>());

      int res = 0;
      for (int i = 1; i < nums.size(); ++i)
        if (nums[i-1] > nums[i])
          res += i;

      return res;
    }
};


int main() {
  EXECS(Solution::reductionOperations);
  return 0;
}