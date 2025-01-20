#include <local_leetcode.hpp>

class Solution {
  private:
    int res;
    vector<vector<int>> graph;
    vector<vector<int>> graph_rev;
  public:
    int minReorder(int n, vector<vector<int>>& connections) {
      graph = vector<vector<int>>(n);
      graph_rev = vector<vector<int>>(n);
      for (auto& edge : connections) {
        graph[edge[0]].push_back(edge[1]);
        graph_rev[edge[1]].push_back(edge[0]);
      }

      res = 0;
      dfs(-1, 0);
      return res;
    }

    void dfs(int v, int w) {
      for (int e : graph[w]) {
        if (e==v) continue;
        dfs(w, e);
        ++res;
      }

      for (int e : graph_rev[w]) {
        if (e==v) continue;
        dfs(w, e);
      }
    }

    int minReorderNew(int n, vector<vector<int>>& connections) {
      vector<vector<pair<int, int>>> graph(n);
      for (auto& con : connections) {
        graph[con[0]].emplace_back(con[1], 1);
        graph[con[1]].emplace_back(con[0], 0);
      }

      function<int (int, int)> traverse = [&graph, &traverse] (int u, int v) -> int {
        int res = 0;
        for (auto [w, d] : graph[v])
          if (w != u)
            res += traverse(v, w) + d;

        return res;
      };

      return traverse(-1, 0);
    }
};


int main() {
  EXECS(Solution::minReorder);
  EXECS(Solution::minReorderNew);
  return 0;
}