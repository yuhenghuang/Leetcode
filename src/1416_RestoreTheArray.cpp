#include <local_leetcode.hpp>

class Solution {
  public:
    int numberOfArrays(string s, int _k) {
      constexpr int mod = 1e9 + 7;

      string k = to_string(_k);
      string_view sv(k);

      int n = s.size();
      int m = k.size();

      int dp[n+1];
      memset(dp, 0, sizeof(dp));
      dp[0] = 1;

      for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m && i - j >= 0; ++j) 
          if (s[i - j] > '0' && (j < m || string_view(s.data() + i - j, j) <= sv))
            dp[i] = (dp[i] + dp[i - j]) % mod;

      return dp[n];
    }
};


int main() {
  EXECS(Solution::numberOfArrays);
  return 0;
}