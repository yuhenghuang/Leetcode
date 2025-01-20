#include <local_leetcode.hpp>

class Solution {
  public:
    int countVowelPermutation(int n) {
      constexpr int mod = 1e9 + 7;

      vector<int> prev(5, 1), next(5);

      // ae
      // ea, ei
      // ia, ie, io, iu
      // oi, ou
      // ua
      while (--n) {
        next[0] = ((prev[1] + prev[2]) % mod + prev[4]) % mod;
        next[1] = (prev[0] + prev[2]) % mod;
        next[2] = (prev[1] + prev[3]) % mod;
        next[3] = prev[2] % mod;
        next[4] = (prev[2] + prev[3]) % mod;

        swap(prev, next);
      }

      return reduce(
        prev.begin(), 
        prev.end(), 
        0, 
        [](int x, int y) { return (x + y) % mod; }
      );
    }
};


int main() {
  EXECS(Solution::countVowelPermutation);
  return 0;
}