#include <vector>
using namespace std;

class Solution {
  private:
    vector<bool> visited;
    vector<vector<int>> graph;
  public:
    int makeConnected(int n, vector<vector<int>>& connections) {
      int res = -1;
      if (connections.size()<n-1) return res;

      graph = vector<vector<int>>(n);
      for (auto& edge : connections) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
      }

      visited = vector<bool>(n, false);
      for (int i=0; i<n; ++i)
        if (!visited[i]) {
          ++res;
          dfs(-1, i);
        }
      return res;
    }

    void dfs(int prev, int cur) {
      visited[cur] = true;
      for(int& next : graph[cur])
        if (next != prev && !visited[next])
          dfs(cur, next);
    }
};