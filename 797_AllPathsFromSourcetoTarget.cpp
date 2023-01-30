#define _LL_NONTRIVIAL_SOLUTION_CTOR
#include <local_leetcode.hpp>

class Solution {
  private:
    int target;
    vector<int> stack;
    vector<vector<int>> res;

    void dfs(vector<vector<int>>& graph) {
      if (stack.back()==target) {
        res.push_back(stack);
        return;
      }

      for (int w : graph[stack.back()]) {
        stack.push_back(w);
        dfs(graph);
        stack.pop_back();
      }
    }
  public:
    Solution(): stack{0} { }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
      res.clear();
      target = (int) graph.size() - 1;

      dfs(graph);
      return res;
    }

    vector<vector<int>> allPathsSourceTargetBFS(vector<vector<int>>& graph) {
      int n = graph.size();

      // indegree of node i
      vector<int> indegree(n);
      for (int i = 0; i < n; ++i)
        for (const int& j : graph[i])
          ++indegree[j];

      // paths from 0 to i
      vector<vector<int>> paths[n];
      paths[0].push_back({0});

      queue<int> q;
      q.push(0);

      while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (const int& v : graph[u]) {

          // update all paths of 0 -> u to 0 -> u -> v
          for (const vector<int>& p : paths[u]) 
            paths[v].emplace_back(p).push_back(v);

          // push v to the queue when all nodes directed to it are visited
          // early stop if v is target (n - 1)
          if (--indegree[v] == 0 && v != n - 1)
            q.push(v);
        }
      }

      return paths[n-1];
    }
};

int main() {
  EXECS(Solution::allPathsSourceTarget);
  EXECS(Solution::allPathsSourceTargetBFS);
  return 0;
}