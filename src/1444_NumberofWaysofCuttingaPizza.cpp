#include <local_leetcode.hpp>

class Solution {
  public:
    int ways(vector<string>& pizza, int k) {
      constexpr int mod = 1e9 + 7;

      int m = pizza.size();
      int n = pizza[0].size();

      int dp[50][50][10];
      memset(dp, -1, sizeof(dp));

      vector<uint64_t> bits;
      for (auto& p : pizza) {
        uint64_t b = 0;
        for (char c : p)
          b = (b << 1) | (c == 'A' ? 1 : 0);

        bits.push_back(b);
      }

      function<int (int, int, int)> dfs = [m, n, &dp, &bits, &dfs] (int i, int j, int k) -> int {
        if (i == m || j == n)
          return 0;
        if (dp[i][j][k] >= 0)
          return dp[i][j][k];

        int imin = m; // upmost row with apple

        uint64_t b = 0;
        uint64_t mask = (static_cast<uint64_t>(1) << (n - j)) - 1;

        for (int r = m - 1; r >= i; --r)
          if ((bits[r] & mask)> 0) {
            b |= bits[r];
            imin = r;
          }

        // mask to only least (n - j) bits
        b &= mask;

        // the last piece has apple or not
        if (k == 0 || b == 0)
          return dp[i][j][k] = imin < m ? 1 : 0;

        // leftmost column with apple
        int jmin = n - (numeric_limits<uint64_t>::digits - __builtin_clzll(b));

        int res = 0;
        for (int r = imin + 1; r < m; ++r) {
          res += dfs(r, j, k - 1);

          if (res > mod)
            res -= mod;
        }

        for (int c = jmin + 1; c < n; ++c) {
          res += dfs(i, c, k - 1);

          if (res > mod)
            res -= mod;
        }

        return dp[i][j][k] = res;
      };

      return dfs(0, 0, k - 1);
    }
};


int main() {
  EXECS(Solution::ways);
  return 0;
}