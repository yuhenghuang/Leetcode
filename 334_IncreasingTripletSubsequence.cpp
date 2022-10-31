#include <local_leetcode.hpp>

class Solution {
  public:
    bool increasingTriplet(vector<int>& nums) {
      int n = nums.size();
      vector<int> right_max(n);

      int r = INT_MIN;
      for (int i=n-1; i>1; --i) {
        r = max(r, nums[i]);
        right_max[i] = r;
      }

      int l = INT_MAX;
      for (int i=1; i<n-1; ++i) {
        l = min(l, nums[i-1]);
        if (l<nums[i] && nums[i]<right_max[i+1])
          return true;
      }

      return false;
    }

    bool increasingTripletO1(vector<int>& nums) {
      int num1 = INT_MAX;
      int num2 = INT_MAX;

      for (const int& num : nums) {
        if (num > num2)
          return true;
        else if (num > num1)
          num2 = num;
        else
          num1 = num;
      }

      return false;
    }
};


int main() {
  EXECS(Solution::increasingTriplet);
  EXECS(Solution::increasingTripletO1);
  return 0;
}