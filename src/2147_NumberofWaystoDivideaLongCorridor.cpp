#include <local_leetcode.hpp>

class Solution {
  public:
    int numberOfWays(string corridor) {
      constexpr long long mod = 1e9 + 7;

      // even seats found
      bool flag = true;

      // plants after nearest two seats + 1
      int count = 1;

      long long res = 0;
      for (char c : corridor) {
        if (c == 'P') {
          if (flag)
            ++count;
        }
        else {
          // first seat
          if (flag) {
            res = max((res * count) % mod, 1LL);
            flag = false;
          }
          // second seat
          else {
            count = 1;
            flag = true;
          }
        }
      }

      return flag ? res : 0;
    }
};


int main() {
  EXECS(Solution::numberOfWays);
  return 0;
}