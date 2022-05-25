#include <local_leetcode.hpp>

class Solution {
  public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      typedef pair<int, int> ii_t;

      vector<vector<ii_t>> graph(n+1);

      for (auto& t : times)
        graph[t[0]].emplace_back(t[1], t[2]);


      vector<bool> seen(n+1);

      priority_queue<ii_t, vector<ii_t>, greater<ii_t>> heap;

      heap.emplace(0, k);

      int res = 0;
      while (!heap.empty()) {
        auto [t, u] = heap.top();
        heap.pop();

        if (seen[u])
          continue;

        res = t;
        seen[u] = true;

        for (auto& [v, w] : graph[u])
          heap.emplace(t + w, v);
      }

      // cannot reach all nodes
      for (int i = 1; i <= n; ++i)
        if (!seen[i])
          return -1;

      return res;
    }
};


int main() {
  EXECS(Solution::networkDelayTime);
  return 0;
}