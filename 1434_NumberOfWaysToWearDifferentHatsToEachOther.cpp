#include "utils3.hpp"

class Solution {
  public:
    int numberWays(vector<vector<int>>& hats) {
      // possible improvement
      // encoding hats in an efficient way to reduce 40 to a possible smaller value

      constexpr int mod = 1e9 + 7;

      int n = hats.size();

      // hats to bits
      vector<long> bits(n);
      for (int i = 0; i < n; ++i)
        for (int hat : hats[i]) 
          bits[i] |= 1L << hat;

      int N = 1 << n;

      // max id of hats used, combinations of people (total 2^n cases)
      int dp[41][N];

      // # of combinations for no-person case is 1
      for (int i = 0 ; i <= 40; ++i)
        dp[i][0] = 1;
      
      // # of combinations for no-hat case is 0
      for (int j = 1; j < N; ++j)
        dp[0][j] = 0;


      // O(40 * 2^n * n)
      for (int i = 1; i <= 40; ++i) 
        for (int j = 1; j < N; ++j) {
          // avoid multiple accesses to array
          int res = dp[i - 1][j];

          for (int k = 0; k < n; ++k)
            // kth person in j and kth person has hat i
            if (((j >> k) & 1) > 0 && ((bits[k] >> i) & 1) > 0) {
              res += dp[i - 1][j ^ (1 << k)];

              // avoid module operation which is slow
              if (res > mod)
                res -= mod;
            }

          dp[i][j] = res;
        }

      return dp[40][N-1];
    }
};


int main() {
  UFUNCS(Solution::numberWays);
  return 0;
}