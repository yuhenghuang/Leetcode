#include "utils3.hpp"

class Solution {
  private:
    int count_neighbors(int b, int bit, int m) {
      return (((b >> 1) & bit) > 0) + (((b << 1) & bit) > 0) + (((b >> m) & bit) > 0) + (((b << m) & bit) > 0);
    }

  public:
    int getMaxGridHappinessTLE(const int m, const int n, int introvertsCount, int extrovertsCount) {
      // TLE!!!
      constexpr long mask = INT_MAX;

      unordered_map<long, int> dp[introvertsCount+1][extrovertsCount+1];
      dp[0][0][0L] = 0;

      int res = 0;
      for (int i = 0; i <= introvertsCount; ++i)
        for (int j = 0; j <= extrovertsCount; ++j) {
          for (auto& p : dp[i][j]) {
            int ibit = p.first >> 31;
            int ebit = p.first & mask;

            long bit = ibit | ebit;
            for (int r = 0; r < m; ++r)
              for (int c = 0; c < n; ++c) {
                long b = 1 << (r * (n+1) + c);
                if ((b & bit) == 0) {
                  int icount = count_neighbors(b, ibit, n+1);
                  int ecount = count_neighbors(b, ebit, n+1);

                  int temp;
                  // dp[i+1][j][p.first & (b << 31)] = 120 - 30 * (ecount + icount) + 20 * ecount - 30 * icount;
                  if (i < introvertsCount) {
                    temp = p.second + 120 - 10 * ecount - 60 * icount;
                    if (temp > res)
                      res = temp;
                    dp[i+1][j][p.first | (b << 31)] = temp;
                  }


                  // dp[i][j+1][p.first & b] = 40 + 20 * (ecount + icount) + 20 * ecount - 30 * icount;
                  if (j < extrovertsCount) {
                    temp = p.second + 40 + 40 * ecount  - 10 * icount;
                    if (temp > res)
                      res = temp;
                    dp[i][j+1][p.first | b] = temp;
                  }

                }
              }


          }
        }

      return res;
    }
};


int main() {
  UFUNCS(Solution::getMaxGridHappinessTLE);
  return 0;
}