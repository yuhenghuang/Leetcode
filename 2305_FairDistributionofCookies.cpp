#include <local_leetcode.hpp>

class Solution {
  public:
    int distributeCookies(vector<int>& cookies, int k) {
      // O(2^n + k * 2^n * 2^n + 2^n)
      // O(2^n * (2 + k * 2^n))
      // overall O(k * 2^(2n))

      int dp[7][256];
      memset(dp, 0, (k-1) * sizeof(int[256]));

      const int n = cookies.size();
      const uint8_t ones = (1 << n) - 1;

      for (uint8_t t = 0, b = 1; t < ones; ++t, ++b) {
        int j = __builtin_ctz(b);
        dp[0][b] = dp[0][b ^ (1 << j)] + cookies[j];
      }

      for (int i = 1; i < k - 1; ++i) {
        for (uint8_t b = 1; b < ones; ++b) {
          if (__builtin_popcount(b) > i) {
            int res = INT_MAX;
            for (uint8_t p = b ^ ones; (p & b) < b;) {
              p = (p + 1) & b;

              if (__builtin_popcount(p) > i - 1)
                res = min(res, max(dp[0][b ^ p], dp[i-1][p]));

              p |= (b ^ ones);
            }

            dp[i][b] = res;
          }
        }
      }

      int res = INT_MAX;
      for (uint8_t b = 1; b < ones; ++b)
        if (__builtin_popcount(b) > k - 2)
          res = min(res, max(dp[0][ones ^ b], dp[k-2][b]));

      return res;
    }
};


int main() {
  EXECS(Solution::distributeCookies);
  return 0;
}