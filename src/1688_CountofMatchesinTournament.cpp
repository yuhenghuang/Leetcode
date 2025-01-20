#include <local_leetcode.hpp>

class Solution {
  public:
    int numberOfMatches(int n) {
      int res = 0;

      while (n > 1) {
        res += (n >> 1) + (n & 1);

        n >>= 1;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::numberOfMatches);
  return 0;
}