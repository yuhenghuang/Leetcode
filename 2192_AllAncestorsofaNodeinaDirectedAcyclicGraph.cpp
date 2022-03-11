#include <local_leetcode.hpp>

class Solution {
  public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
      vector<int> indegree(n);
      vector<vector<int>> graph(n);

      for (auto& e : edges) {
        graph[e[0]].push_back(e[1]);
        ++indegree[e[1]];
      }

      queue<int> q;
      for (int i = 0; i < n; ++i)
        if (indegree[i] == 0)
          q.push(i);

      vector<set<int>> ancestors(n);
      while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (const int& v : graph[u]) {
          ancestors[v].insert(ancestors[u].begin(), ancestors[u].end());
          ancestors[v].insert(u);
          if (--indegree[v] == 0)
            q.push(v);
        }
      }

      vector<vector<int>> res(n);
      for (int i = 0; i < n; ++i)
        res[i].assign(ancestors[i].begin(), ancestors[i].end());

      return res;
    }
};


int main() {
  EXECS(Solution::getAncestors);
  return 0;
}