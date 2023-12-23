#include <local_leetcode.hpp>

class Solution {
  public:
    int maxProduct(vector<int>& nums) {
      int first = max(nums[0], nums[1]);
      int second = min(nums[0], nums[1]);

      for (int i = 2; i < nums.size(); ++i) {
        int num = nums[i];
        if (num > first) {
          second = first;
          first = num;
        }
        else if (num > second)
          second = num;
      }

      return (first - 1) * (second - 1);
    }
};


int main() {
  EXECS(Solution::maxProduct);
  return 0;
}