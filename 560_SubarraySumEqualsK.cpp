#include <local_leetcode.hpp>

class Solution {
  public:
    int subarraySum(vector<int>& nums, int k) {
      // prefix sum, count
      unordered_map<int, int> m;
      m[0] = 1;

      int prefix = 0;
      int res = 0;
      for (int i = 0; i < nums.size(); ++i) {
        prefix += nums[i];

        res += m[prefix - k];

        ++m[prefix];
      }

      return res;
    }
};


int main() {
  EXECS(Solution::subarraySum);
  return 0;
}