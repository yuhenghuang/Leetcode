#include "utils3.hpp"

class Solution {
  private:
    void dfs(int i, int jumps, const int a, const int b, vector<int>& dp) {
      if (i < 0 || i >= dp.size() || dp[i] < jumps)
        return;

      dp[i] = jumps;
      
      dfs(i + a, jumps + 1, a, b, dp);

      if (i >= b)
        dfs(i - b + a, jumps + 2, a, b, dp);
    }

  public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
      bool dp[10000][2] = {0};
      for (int i : forbidden)
        if (i < 10001)
          dp[i][0] = dp[i][1] = true;

      int res = 0;

      queue<pair<int, int>> q;
      q.emplace(0, 0);
      
      while (!q.empty()) {
        int n = q.size();
        while (n--) {
          auto [i, s] = q.front();



          q.pop();
        }
        ++res;
      }

      return -1;
    }

    int minimumJumpsWrong(vector<int>& forbidden, int a, int b, int x) {
      // wrong answer

      // size of dp
      // [0, n)
      int n = x + b + 1;

      vector<int> dp(n, INT_MAX - 1);
      for (int i : forbidden)
        if (i < n)
          dp[i] = -2;

      dfs(0, 0, a, b, dp);

      int res = dp[n-1] < 0 ? dp[x] : min(dp[x], dp[n-1] + 1);
      return res == INT_MAX - 1 ? -1 : res;
    }
};


int main() {
  UFUNCS(Solution::minimumJumps);
  UFUNCS(Solution::minimumJumpsWrong);
  return 0;
}