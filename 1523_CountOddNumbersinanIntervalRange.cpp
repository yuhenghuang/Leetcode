#include <local_leetcode.hpp>

class Solution {
  public:
    int countOdds(int low, int high) {
      int len = high - low + 1;
      return (len >> 1) + (len & low & 1 ? 1 : 0);
    }
};


int main() {
  EXECS(Solution::countOdds);
  return 0;
}