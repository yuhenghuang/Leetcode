#include <local_leetcode.hpp>

class Solution {
  public:
    double angleClock(int hour, int minutes) {
      double res = abs(minutes * 5.5 - hour * 30);

      return res > 180 ? 360 - res : res;
    }
};


int main() {
  EXECS(Solution::angleClock);
  return 0;
}