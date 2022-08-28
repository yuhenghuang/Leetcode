#include <local_leetcode.hpp>

class Solution {
  public:
    bool isPossible(vector<int>& nums) {
      // count of previous consecutive subsequences
      // length of 0, 1, 2, 3 and more
      int prev[4] = {0};

      prev[0] = 1;

      for (int i = 1; i < (int) nums.size(); ++i) {
        if (nums[i-1] == nums[i]) {
          // do nothing
        }
        else if (nums[i-1] + 1 == nums[i]) {
          if (prev[0] < prev[1] + prev[2])
            return false;
          else {
            int temp = prev[0] - prev[1] - prev[2] - prev[3];

            prev[3] = prev[2] + prev[3] + min(0, temp);
            prev[2] = prev[1];
            prev[1] = max(0, temp);
            prev[0] = 0;
          }
        }
        else {
          if (prev[1] > 0 || prev[0] < prev[2] || (prev[0] - prev[2] > prev[3]))
            return false;
          else
            memset(prev, 0, sizeof(prev));
        }

        ++prev[0];
      }

      return prev[1] == 0 && prev[0] >= prev[2] && (prev[0] - prev[2] <= prev[3]);
    }
};


int main() {
  EXECS(Solution::isPossible);
  return 0;
}