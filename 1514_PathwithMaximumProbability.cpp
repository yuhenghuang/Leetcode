#include <local_leetcode.hpp>

class Solution {
  public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
      typedef pair<double, int> pdi_t;

      vector<pdi_t> graph[n];
      for (int i = 0; i < edges.size(); ++i) {
        graph[edges[i][0]].emplace_back(succProb[i], edges[i][1]);
        graph[edges[i][1]].emplace_back(succProb[i], edges[i][0]);
      }

      bool seen[n];
      memset(seen, false, sizeof(seen));

      priority_queue<pdi_t, vector<pdi_t>> heap;
      heap.emplace(1.0, start);

      while (!heap.empty()) {
        auto [prob, v] = heap.top();
        heap.pop();

        if (seen[v])
          continue;
        else if (v == end)
          return prob;

        seen[v] = true;
        for (auto& p : graph[v])
          if (!seen[p.second]) 
            heap.emplace(prob * p.first, p.second);

      }

      return 0;
    }
};


int main() {
  EXECS(Solution::maxProbability);
  return 0;
}