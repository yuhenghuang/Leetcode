#include <local_leetcode.hpp>

class Solution {
  public:
    bool checkSubarraySum(vector<int>& nums, int k) {
      unordered_set<int> s;

      int prev = 0;
      int curr = 0;
      for (int i = 0; i < nums.size(); ++i) {
        curr = (curr + nums[i]) % k;

        if (s.count(curr))
          return true;

        s.insert(prev % k);
        prev += nums[i]; // by constraints of the input, no need to consider overflow
      }

      return false;
    }
};


int main() {
  EXECS(Solution::checkSubarraySum);
  return 0;
}