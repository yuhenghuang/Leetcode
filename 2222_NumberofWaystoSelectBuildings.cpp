#include <local_leetcode.hpp>

class Solution {
  public:
    long long numberOfWays(string s) {
      long long dp[4][2] = {{0}};

      dp[0][0] = dp[0][1] = 1;

      for (char c : s) {
        int b = c - '0';

        for (int i = 3; i > 0; --i) 
          dp[i][b] += dp[i-1][1 ^ b];
      }

      return dp[3][0] + dp[3][1];
    }
};


int main() {
  EXECS(Solution::numberOfWays);
  return 0;
}