#include <local_leetcode.hpp>

class Solution {
  private:
    int res;

    void dfs(int v, int t, int s, vector<int>& values, vector<vector<pair<int, int>>>& graph, vector<int>& count) {
      if (t < 0)
        return;

      // add value if visit first time
      if (count[v] == 0) 
        s += values[v];

      if (v == 0 && s > res)
        res = s;

      ++count[v];
      
      for (auto const& [w, time] : graph[v])
        dfs(w, t - time, s, values, graph, count);

      --count[v];
    }

  public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
      int n = values.size();

      vector<int> count(n);
      vector<vector<pair<int, int>>> graph(n);

      for (auto& e : edges) {
        graph[e[0]].emplace_back(e[1], e[2]);
        graph[e[1]].emplace_back(e[0], e[2]);
      }

      res = 0;
      dfs(0, maxTime, 0, values, graph, count);

      return res;
    }
};


int main() {
  EXECS(Solution::maximalPathQuality);
  return 0;
}