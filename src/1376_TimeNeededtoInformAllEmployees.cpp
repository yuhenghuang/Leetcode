#include <local_leetcode.hpp>

class Solution {
  private:
    vector<vector<int>> graph;
    int res;

    void dfs(int v, int t, vector<int>& informTime) {
      if (graph[v].size()==0) {
        res = max(res, t);
        return;
      }

      for (int& w : graph[v]) 
        dfs(w, t+informTime[v], informTime);
    }

  public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
      graph = vector<vector<int>>(n);
      for (int i=0; i<n; ++i)
        if (i!=headID)
          graph[manager[i]].push_back(i);

      res = 0;
      dfs(headID, 0, informTime);
      return res;
    }

    int numOfMinutesTopology(int n, int headID, vector<int>& manager, vector<int>& informTime) {
      vector<int> indegree(n);
      queue<int> q;

      for (int i = 0; i < n; ++i) 
        if (i != headID) [[likely]] {
          ++indegree[manager[i]];

          if (informTime[i] == 0)
            q.push(i);
        }

      vector<int> dp(n);
      while (!q.empty()) {
        int u = q.front();
        q.pop();

        int v = manager[u];

        dp[v] = max(dp[v], dp[u] + informTime[u]);
        if (--indegree[v] == 0 && v != headID)
          q.push(v);
      }

      return dp[headID] + informTime[headID];
    }

    int numOfMinutesDP(int n, int headID, vector<int>& manager, vector<int>& informTime) {
      vector<int> dp(n, -1);

      function<int (int)> dfs = [&dp, &manager, &informTime, &dfs] (int u) ->int {
        if (u == -1)
          return 0;
        else if (dp[u] >= 0)
          return dp[u];

        return dp[u] = dfs(manager[u]) + informTime[u];
      };

      int res = 0;
      for (int i = 0; i < n; ++i)
        if (informTime[i] == 0)
          res = max(res, dfs(i));

      return res;
    }
};


int main() {
  EXECS(Solution::numOfMinutes);
  EXECS(Solution::numOfMinutesTopology);
  EXECS(Solution::numOfMinutesDP);

  return 0;
}