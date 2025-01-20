#include <local_leetcode.hpp>

class Solution {
  public:
    int minimizeArrayValue(vector<int>& nums) {
      int altitude = nums[0];
      int hill = 0;
      int64_t valley = 0;

      for (int i = 1; i < (int) nums.size(); ++i) {
        int diff = nums[i] - altitude;
        if (diff < 0)
          valley -= diff;
        else if (diff > 0) {
          if (diff <= valley)
            valley -= diff;
          else {
            diff -= valley;
            valley = 0;

            hill += diff;

            altitude += hill / (i + 1);
            hill %= i + 1;
          }
        }
      }

      return altitude + (hill > 0);
    }
};


int main() {
  EXECS(Solution::minimizeArrayValue);
  return 0;
}