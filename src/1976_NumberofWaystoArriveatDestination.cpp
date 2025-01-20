#include <local_leetcode.hpp>

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
      constexpr int mod = 1e9 + 7;

      typedef pair<int, long> pair_t;
      vector<vector<pair_t>> graph(n);

      for (auto& r : roads) {
        graph[r[0]].emplace_back(r[1], r[2]);
        graph[r[1]].emplace_back(r[0], r[2]);
      }

      bool walked[n][n];
      memset(walked, 0, sizeof(walked));
      
      vector<long> time(n, LONG_MAX);
      vector<int> dp(n);
      dp[0] = 1;

      typedef tuple<long, int, int> tuple_t;
      priority_queue<tuple_t, vector<tuple_t>, greater<tuple_t>> heap;
      heap.emplace(0L, 0, 0);

      while (!heap.empty()) {
        auto [t, v, u] = heap.top();
        heap.pop();

        if (t > time[v] || walked[u][v])
          continue;
        else if (t == time[v]) 
          dp[v] = (dp[v] + dp[u]) % mod;
        else {
          time[v] = t;
          dp[v] = dp[u];
        }

        walked[u][v] = true;

        for (auto& p : graph[v]) 
          heap.emplace(t + p.second, p.first, v);
      }

      return dp[n-1];
    }
};


int main() {
  EXECS(Solution::countPaths);
  return 0;
}