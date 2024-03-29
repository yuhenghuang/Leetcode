#include "utils3.hpp"

class Solution {
  public:
    int hammingDistance(int x, int y) {
      int res = 0;
      while (x>0 || y>0) {
        res += (x & 1) ^ (y & 1);
        x >>= 1;
        y >>= 1;
      }
      return res;
    }
};

int main() {
  UFUNCS(Solution::hammingDistance);
  return 0;
}