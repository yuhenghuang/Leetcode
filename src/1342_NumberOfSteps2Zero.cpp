#include <local_leetcode.hpp>

class Solution {
public:
    int numberOfSteps(int num) {
      if (num==0)
        return 0;

      return 1 + ((num & 1) ? numberOfSteps(num ^ 1) : numberOfSteps(num >> 1));
    }

    int numberOfStepsNew(int num) {
      if (num == 0)
        return 0;

      // move largest bit -> position 0 + flip all 1s into 0s
      return 31 - __builtin_clz(num) + __builtin_popcount(num);
    }
};


int main() {
  EXECS(Solution::numberOfSteps);
  EXECS(Solution::numberOfStepsNew);
  return 0;
}