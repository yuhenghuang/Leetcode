#include "utils2.hpp"

class Solution {
  public:
    int kInversePairs(int n, int k) {
      constexpr int mod = 1e9 + 7;

      vector<int> prev(k + 1);
      vector<int> next(k + 1);
      prev[0] = 1;
      next[0] = 1;

      for (int i = 1; i < n; ++i) {
        for (int j = 0; j < k; ++j)
          // must handle negative values due to module and subtraction
          next[j+1] = ((next[j] + prev[j + 1] - (j < i ? 0 : prev[j - i])) % mod + mod) % mod;

        prev = next;
      }

      return prev[k];
    }
};


int main() {
  UFUNC(Solution::kInversePairs);
  return 0;
}