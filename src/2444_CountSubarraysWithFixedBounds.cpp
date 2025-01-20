#include <local_leetcode.hpp>

class Solution {
  public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
      int64_t res = 0;

      int j = -1; // left bound of sliding window
      int minI = -1, maxI = -1;

      for (int i = 0; i < (int) nums.size(); ++i) {
        int num = nums[i];
        if (num > maxK || num < minK) {
          minI = maxI = -1;
          j = i;
        }
        else {
          if (num == maxK)
            maxI = i;

          if (num == minK)
            minI = i;

          if (maxI >= 0 && minI >= 0)
            res += min(maxI, minI) - j;
        }
      }

      return res;
    }
};


int main() {
  EXECS(Solution::countSubarrays);
  return 0;
}