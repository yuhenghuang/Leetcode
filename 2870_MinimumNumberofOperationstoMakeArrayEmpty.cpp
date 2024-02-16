#include <local_leetcode.hpp>

class Solution {
  public:
    int minOperations(vector<int>& nums) {
      unordered_map<int, int> m;
      for (int num : nums)
        ++m[num];

      int res = 0;
      for (auto [num, freq] : m) {
        if (freq == 1)
          return -1;

        /*
          op = freq / 3, remainder = freq % 3

          remainder == 0, res += op
          remainder == 1, res += op - 1 + 2 equiv. (op + 1)
          remainder == 2, res += op + 1
        */
        res += freq / 3 + (freq % 3 ? 1 : 0);
      }

      return res;
    }
};


int main() {
  EXECS(Solution::minOperations);
  return 0;
}