#include "utils2.hpp"

class Solution {
  public:
    int countPrimes(int n) {
      bool memo[n+1];
      memset(memo, 0, n);

      for (int i = 2; i * i < n; ++i) {
        if (!memo[i]) {
          for (int j = i * i; j < n; j += i)
            memo[j] = true;
        }
      }

      int res = 0;
      for (int i = 2; i < n; ++i)
        if (!memo[i])
          ++res;

      return res;
    }
};


int main() {
  UFUNC(Solution::countPrimes);
  return 0;
}