#include "utils.hpp"

class Solution {
  public:
    int smallestRepunitDivByK(int K) {
      vector<bool> seen(K+1, false);
      int N = 0, res = 1;
      while (!seen[N]) {
        seen[N] = true;
        N = (10 * N + 1) % K;
        if (N==0)
          return res;
        ++res;
      }
      return -1;
    }
};


int main() {
  UFUNC(Solution::smallestRepunitDivByK);
  return 0;
}