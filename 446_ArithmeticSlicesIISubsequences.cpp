#include <local_leetcode.hpp>

class Solution {
  public:
    int numberOfArithmeticSlices(vector<int>& nums) {
      int n = nums.size();

      if (n < 3)
        return 0;

      // (difference, count) [index]
      unordered_map<int, int> dp[n];

      int res = 0;

      for (int i = 1; i < n; ++i) {
        int64_t num = nums[i];

        for (int j = 0; j < i; ++j) {
          int64_t d = num - nums[j];

          if (INT_MIN <= d && d <= INT_MAX) {
            int& tmp = dp[i][d];
            ++tmp; // count of nums[j] - num[i]

            auto iter = dp[j].find(d);
            if (iter != dp[j].end()) {
              res += iter->second;
              tmp += iter->second;
            }
          }
        }
      }


      return res;
    }
};


int main() {
  EXECS(Solution::numberOfArithmeticSlices);
  return 0;
}