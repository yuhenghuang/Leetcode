#include "utils.hpp"

class Solution {
  public:
    int reachNumber(int target) {
      if (target<0)
        target = -target;

      /*
      find 1, 2, ..., k sum up larger than target
      if surplus is even, change the sign of one number in [1, k] will reach target
      thus the result is k.

      otherwise, adding k+1 to see if surplus is even now
      if k is even, then k+1 is the answer because odd (k+1) + odd (surplus) is even.
      otherwise the answer is k+2
      */
      int k = 0;
      while (target>0)
        target -= ++k;

      return (target%2) ? (k+1 + k%2) : k;
    }
};


int main() {
  UFUNC(Solution::reachNumber);
  return 0;
}