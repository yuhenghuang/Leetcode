#include <local_leetcode.hpp>

class Solution {
  public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
      const int n = nums.size();

      vector<int> updowns(n + 1);
      for (auto& q : queries) {
        ++updowns[q[0]];
        --updowns[q[1] + 1];
      }

      int height = 0;
      for (int i = 0; i < n; ++i) {
        height += updowns[i];
        if (height < nums[i])
          return false;
      }

      return true;
    }
};


int main() {
  EXECS(Solution::isZeroArray);
  return 0;
}