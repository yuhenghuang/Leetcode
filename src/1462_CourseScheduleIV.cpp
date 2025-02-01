#include <local_leetcode.hpp>

class Solution {
  private:
    void dfs(int u, const vector<vector<int>>& graph, vector<bool>& visited, vector<vector<bool>>& ancestor) {
      if (visited[u])
        return;

      visited[u] = true;

      for (int v : graph[u]) {
        ancestor[u][v] = true;

        dfs(v, graph, visited, ancestor);
        for (int w = 0; w < (int) graph.size(); ++w)
          if (ancestor[v][w])
            ancestor[u][w] = true;
      }
    }


  public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
      vector<bool> visited(n);

      vector<vector<bool>> ancestor(n, vector<bool>(n));

      vector<vector<int>> graph(n);
      for (auto & p : prerequisites)
        graph[p[0]].push_back(p[1]);

      for (int i = 0; i < n; ++i)
        dfs(i, graph, visited, ancestor);

      vector<bool> res;
      res.reserve(queries.size());

      for (auto& q : queries) 
        res.push_back(ancestor[q[0]][q[1]]);

      return res;
    }
};


int main() {
  EXECS(Solution::checkIfPrerequisite);
  return 0;
}