#include <local_leetcode.hpp>

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
      if (x == 0)
        return 0;

      int n = 6004;
      
      // 0 backward, 1 forward
      vector<bool> dp[2];

      dp[0].assign(n+1, false);
      dp[1].assign(n+1, false);

      dp[1][0] = dp[0][0] = true;

      for (const int& f : forbidden)
        if (f <= n)
          dp[0][f] = dp[1][f] = true;

      queue<pair<int, bool>> q;
      q.emplace(0, true);

      int res = 1;
      while (!q.empty()) {
        int s = q.size();

        while (s--) {
          auto [v, front] = q.front();
          q.pop();

          int w;
          w = v + a;

          if (w == x)
            return res;
          else if (w <= n && !dp[0][w]) {
            dp[0][w] = dp[1][w] = true;
            q.emplace(w, true);
          }
          
          // can move backward
          if (front) {
            w = v - b;

            if (w == x)
              return res;
            else if (w >= 0 && w <= n && !dp[1][w]) {
              dp[1][w] = true;
              q.emplace(w, false);
            }
          }
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
  EXECS(Solution::minimumJumps);
  EXECS(Solution::minimumJumpsWrong);
  return 0;
}