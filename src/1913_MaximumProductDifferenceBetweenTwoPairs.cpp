#include <local_leetcode.hpp>

class Solution {
  private:
    template <class Comp>
    int extremeProduct(const vector<int>& nums, Comp comp) {
      int first = comp(nums[0], nums[1]) ? nums[0] : nums[1];
      int second = comp(nums[0], nums[1]) ? nums[1] : nums[0];

      for (int i = 2; i < nums.size(); ++i) {
        int num = nums[i];
        if (comp(num, first)) {
          second = first;
          first = num;
        }
        else if (comp(num, second))
          second = num;
      }

      return first * second;
    }

  public:
    int maxProductDifference(vector<int>& nums) {
      return extremeProduct(nums, greater<>()) - extremeProduct(nums, less<>());
    }
};


int main() {
  EXECS(Solution::maxProductDifference);
  return 0;
}