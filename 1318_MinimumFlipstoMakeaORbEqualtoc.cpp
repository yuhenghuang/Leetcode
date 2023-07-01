#include <local_leetcode.hpp>

class Solution {
  public:
    int minFlips(int a, int b, int c) {
      /*
        a b c flips
        0 0 0 0
        1 0 0 1
        0 1 0 1
        1 1 0 2
        0 0 1 1
        1 0 1 0
        0 1 1 0
        1 1 1 0
      */

      int res = 0;
      for (; (a | b | c) > 0; a >>= 1, b >>= 1, c >>= 1) {
        if (c & 1) {
          if ((a & 1) == 0 && (b & 1) == 0)
            ++res;
        }
        else
          res += (a & 1) + (b & 1);
      }

      return res;
    }
};


int main() {
  EXECS(Solution::minFlips);
  return 0;
}