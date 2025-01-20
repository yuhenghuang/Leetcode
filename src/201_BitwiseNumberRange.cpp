#include "utils3.hpp"

class Solution {
  public:
    int rangeBitwiseAnd(int left, int right) {
      int res = 0;
      for (int shift = 31; shift >= 0; --shift) {
        int lb = (left >> shift) & 1;
        int rb = (right >> shift) & 1;
        if (lb == rb) {
          if (lb > 0)
            res ^= 1 << shift;
        }
        else
          break;
      }

      return res;
    }
};

int main() {
  UFUNCS(Solution::rangeBitwiseAnd);
  return 0;
}