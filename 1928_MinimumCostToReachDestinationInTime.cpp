#include <unordered_set>
#include <unordered_map>
#include "utils3.hpp"

class Solution {
  public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& fees) {
      int n = fees.size();

      // handle duplicate edges
      vector<unordered_set<int>> graph(n);
      // n x n matrix might be too large to fit into memory
      vector<unordered_map<int, int>> times(n);
      for (auto& e : edges) {
        graph[e[0]].insert(e[1]);
        graph[e[1]].insert(e[0]); 
        
        // avoid accessing the same element multiple times
        int* t;
        t = &times[e[0]][e[1]];
        *t = (*t == 0) ? e[2] : min(e[2], *t);
        
        t = &times[e[1]][e[0]];
        *t = (*t == 0) ? e[2] : min(e[2], *t);
      }

      vector<int> costTimes(n, maxTime + 1);

      typedef tuple<int, int, int> tiii;
      priority_queue<tiii, vector<tiii>, greater<tiii>> heap;
      heap.emplace(fees[0], 0, 0);
      costTimes[0] = 0;

      while (!heap.empty()) {
        // fee, time, node
        auto [f, t, v] = heap.top();
        heap.pop();

        if (v == n - 1)
          return f;

        for (int w : graph[v]) {
          int t_next = t + times[v][w];
          if (t_next < costTimes[w]) {
            costTimes[w] = t_next;
            heap.emplace(f + fees[w], t_next, w);
          }
        }
      }

      return -1;
    }
};


int main() {
  UFUNCS(Solution::minCost);
  return 0;
}