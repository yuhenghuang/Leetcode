#include <local_leetcode.hpp>

class Solution {
  public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      typedef pair<int, int> ii_t;

      vector<vector<ii_t>> graph(n);
      for (auto& f : flights)
        graph[f[0]].emplace_back(f[1], f[2]);

      // (city, stop) -> cost
      vector<vector<int>> dp(n, vector<int>(k + 2, INT_MAX));

      // city, stop
      queue<ii_t> q;

      // initialize
      dp[src][0] = 0;
      q.emplace(src, 0);

      while (!q.empty()) {
        auto [u, s] = q.front();
        q.pop();

        for (auto& [v, c] : graph[u])
          if (dp[u][s] +  c < dp[v][s+1]) {
            dp[v][s+1] = dp[u][s] +  c;

            if (s < k && v != dst)
              q.emplace(v, s + 1);
          }
      }

      int res = *min_element(dp[dst].begin(), dp[dst].end());

      return res == INT_MAX ? -1 : res;
    }
};


int main() {
  EXECS(Solution::findCheapestPrice);
  return 0;
}