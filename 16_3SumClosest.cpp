#include <local_leetcode.hpp>

class Solution {
  public:
    int threeSumClosest(vector<int>& nums, int target) {
      sort(nums.begin(), nums.end());

      int n = nums.size();

      int res;
      int dist = INT_MAX;
      for (int i = n - 1; i > 1; --i) {
        if (i == n - 1 || nums[i] != nums[i+1]) {
          int t = target - nums[i];
          int l = 0, r = i - 1;

          while (l < r) {
            int sum = nums[l] + nums[r];

            if (abs(t - sum) < dist) {
              dist = abs(t - sum);
              res = sum + nums[i];
            }

            if (sum > t || (r < i - 1 && nums[r] == nums[r+1]))
              --r;
            else if (sum < t || (l > 0 && nums[l] == nums[l-1]))
              ++l;
            else {
              ++l;
              --r;
            }
          }
        }
      }

      return res;
    }
};


int main() {
  EXECS(Solution::threeSumClosest);
  return 0;
}