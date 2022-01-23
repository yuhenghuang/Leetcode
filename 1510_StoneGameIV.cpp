#include <local_leetcode.hpp>

class Solution {
  private:
    vector<vector<int>> memo;
    bool play(int n, bool alice) {
      if (memo[n][alice]!=-1) return memo[n][alice];

      bool flag = false;
      for (int i=1; i*i<=n; ++i) {
        if (!play(n-i*i, !alice)) {
          flag = true;
          break;
        }
      }

      memo[n][alice] = flag;
      return flag;
    }
  public:
    bool winnerSquareGame(int n) {
      memo = vector<vector<int>>(n+1, vector<int>(2, -1));
      memo[0][0] = 0;
      memo[0][1] = 0;
      return play(n, true);
    }

    bool winnerSquareGameDp(int n) {
      vector<bool> dp(n + 1);
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j * j <= i; ++j)
          if (!dp[i - j * j]) {
            dp[i] = true;
            break;
          }
      }

      return dp[n];
    }
};


int main() {
  EXECS(Solution::winnerSquareGame);
  EXECS(Solution::winnerSquareGameDp);
}