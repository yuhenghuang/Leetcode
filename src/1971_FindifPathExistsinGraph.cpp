#include <local_leetcode.hpp>

class Solution {
  private:
    bool dfs(int u, int d, vector<bool>& seen, const vector<vector<int>>& graph) {
      if (u == d)
        return true;

      seen[u] = true;

      for (const int& v : graph[u])
        if (!seen[v] && dfs(v, d, seen, graph))
          return true;

      return false;
    }

  public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
      vector<vector<int>> graph(n);
      for (auto e : edges) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
      }

      vector<bool> seen(n);

      return dfs(source, destination, seen, graph);
    }
};


int main() {
  EXECS(Solution::validPath);
  return 0;
}