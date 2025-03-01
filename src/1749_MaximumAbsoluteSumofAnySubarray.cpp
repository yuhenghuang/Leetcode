#include <local_leetcode.hpp>

class Solution {
  public:
    int maxAbsoluteSum(vector<int>& nums) {
      int res = INT_MIN;

      int inf = 0, sup = 0;
      int prefix = 0;
      for (int num : nums) {
        prefix += num;

        int tmp = max(abs(prefix - inf), abs(prefix - sup));

        if (tmp > res)
          res = tmp;

        if (prefix < inf)
          inf = prefix;
        else if (prefix > sup)
          sup = prefix;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::maxAbsoluteSum);
  return 0;
}