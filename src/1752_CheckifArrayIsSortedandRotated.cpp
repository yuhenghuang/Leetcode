#include <local_leetcode.hpp>

class Solution {
  public:
    bool check(vector<int>& nums) {
      int up = nums.back() > nums.front();

      for (int i = 1; i < (int) nums.size(); ++i)
        if (nums[i-1] > nums[i])
          ++up;

      return up < 2;
    }
};


int main() {
  EXECS(Solution::check);
  return 0;
}