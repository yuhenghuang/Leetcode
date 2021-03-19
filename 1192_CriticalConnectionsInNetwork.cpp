#include <vector>
using namespace std;

class Solution {
  private:
    int idx=0;
    vector<bool> visited;
    vector<int> lowlink;
    vector<int> index;
    vector<vector<int>> graph;
    vector<vector<int>> res;
  public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
      res.clear();

      graph.resize(n);
      for (auto& edge : connections) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
      }

      visited.assign(n, false);
      lowlink.assign(n, 0);
      index.assign(n, 0);

      dfs(-1, 0);
      return res;
    }

    void dfs(int prev, int cur) {
      index[cur] = idx;
      lowlink[cur] = idx;
      ++idx;
      visited[cur] = true;

      for (int next : graph[cur]) {
        if (next==prev) continue;

        if (!visited[next]) {
          dfs(cur, next);
          lowlink[cur] = min(lowlink[cur], lowlink[next]);
        }
        else 
          lowlink[cur] = min(lowlink[cur], index[next]);

        if (index[cur] < lowlink[next])
          res.push_back({cur, next});
      }
    }
};