#include <local_leetcode.hpp>

class Solution {
  public:
    vector<int> applyOperations(vector<int>& nums) {
      const int n = nums.size();

      vector<int> res(n);
      auto iter = res.begin();

      for (int i = 0; i + 1 < n; ++i)
        if (nums[i] > 0) {
          if (nums[i] == nums[i+1]) {
            *iter++ = nums[i] * 2;
            nums[i+1] = 0;
          }
          else
            *iter++ = nums[i];
        }

      if (nums.back() > 0)
        *iter = nums.back();

      return res;
    }
};


int main() {
  EXECS(Solution::applyOperations);
  return 0;
}