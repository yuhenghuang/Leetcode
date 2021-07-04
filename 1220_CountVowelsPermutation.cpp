#include <numeric>
#include "utils2.hpp"

class Solution {
  public:
    int countVowelPermutation(int n) {
      constexpr int mod = 1e9 + 7;

      vector<int> prev(5, 1), next(5);

      while (--n) {
        next[0] = ((prev[1] + prev[2]) % mod + prev[4]) % mod;
        next[1] = (prev[0] + prev[2]) % mod;
        next[2] = (prev[1] + prev[3]) % mod;
        next[3] = prev[2] % mod;
        next[4] = (prev[2] + prev[3]) % mod;

        swap(prev, next);
      }

      int res = 0;

      for (int num : prev)
        res = (res + num) % mod;

      return res;
    }
};


int main() {
  UFUNC(Solution::countVowelPermutation);
  return 0;
}