#include <local_leetcode.hpp>

class Solution {
  public:
    int findMaxLength(vector<int>& nums) {

      // difference between # of 1s and 0s
      int diff = 0;

      unordered_map<int, int> m {{0, -1}};

      int res = 0;
      for (int i = 0; i < nums.size(); ++i) {
        diff += nums[i] == 0 ? -1 : 1;

        auto iter = m.find(diff);

        if (iter != m.end())
          res = max(res, i - iter->second);
        else
          m[diff] = i;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::findMaxLength);
  return 0;
}