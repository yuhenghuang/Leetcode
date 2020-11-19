#include "utils.hpp"

class Solution {
  public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
      int base = minutesToTest / minutesToDie + 1;
      int digits = 0, total = 1;
      while (total < buckets) {
        total *= base;
        ++digits;
      }
      return digits;
    }
};


int main() {
  UFUNC(Solution::poorPigs);
  return 0;
}