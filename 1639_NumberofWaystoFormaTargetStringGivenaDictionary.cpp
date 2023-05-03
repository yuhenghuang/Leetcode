#include <local_leetcode.hpp>

class Solution {
  public:
    int numWays(vector<string>& words, string target) {
      int n = words[0].size();
      int m = target.size();

      if (n < m)
        return 0;

      constexpr uint64_t mod = 1e9 + 7;

      uint16_t freqs[1000][26];
      memset(freqs, 0, sizeof(uint16_t[26]) * n);

      for (const string& w : words)
        for (int i = 0; i < n; ++i)
          ++freqs[i][w[i] - 'a'];

      // target, words
      // memory can be optimized to O(n)
      uint64_t dp[1001][1001];

      // 1 way to form emtpy target string
      dp[0][0] = 1;
      for (int j = 1; j <= n; ++j)
        dp[0][j] = 1;

      for (int i = 0; i < m; ++i) {
        int k = target[i] - 'a';
        dp[i+1][i] = 0;

        for (int j = i; j < n; ++j) 
          dp[i+1][j+1] = (dp[i][j] * freqs[j][k] + dp[i+1][j]) % mod;
      }

      return dp[m][n];
    }

    int numWaysOn(vector<string>& words, string target) {
      int n = words[0].size();
      int m = target.size();

      if (n < m)
        return 0;

      constexpr uint64_t mod = 1e9 + 7;

      uint16_t freqs[1000][26];
      memset(freqs, 0, sizeof(uint16_t[26]) * n);

      for (const string& w : words)
        for (int i = 0; i < n; ++i)
          ++freqs[i][w[i] - 'a'];

      uint64_t dp[1001];
      for (int j = 0; j <= n; ++j)
        dp[j] = 1;


      for (int i = 0; i < m; ++i) {
        int k = target[i] - 'a';
        uint64_t prev = dp[i] = 0;

        for (int j = i; j < n; ++j) {
          uint64_t tmp = dp[j+1];
          dp[j+1] = (prev * freqs[j][k] + dp[j]) % mod;
          prev = tmp;
        }
      }

      return dp[n];
    }
};


int main() {
  EXECS(Solution::numWays);
  EXECS(Solution::numWaysOn);
  return 0;
}