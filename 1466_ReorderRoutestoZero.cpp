#include <vector>
using namespace std;

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
};