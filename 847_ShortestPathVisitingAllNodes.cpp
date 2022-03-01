#include <local_leetcode.hpp>

class Solution {
  private:
    typedef pair<int, int> pii;

    int dfs(int u, int b, vector<vector<int>>& graph, vector<vector<int>>& dp) {
      if (dp[u][b] != 0)
        return dp[u][b];
      else if ((b ^ (1 << u)) == 0)
        return 0;

      dp[u][b] = INT_MAX - 1;
      for (const int& v : graph[u]) {
        
      }

      return dp[u][b];
    }

  public:
    int shortestPathLengthDFS(vector<vector<int>>& graph) {
      const int n = graph.size();

      if (n < 2)
        return 0;

      const int N = 1 << n;

      // last node visited, visited nodes
      vector<vector<int>> dp(n, vector<int>(N, INT_MAX));

      int res = INT_MAX;

      return res;
    }

    int shortestPathLength(vector<vector<int>>& graph) {
      const int n = graph.size();

      if (n < 2)
        return 0;

      const int N = 1 << n;

      // last node visited, visited nodes
      vector<vector<bool>> dp(n, vector<bool>(N));

      // node, bit
      queue<pii> q;

      for (int i = 0; i < n; ++i) {
        dp[i][1 << i] = true;
        q.emplace(i, 1 << i);
      }

      int res = 1;
      while (!q.empty()) {
        int size = q.size();

        while (size--) {
          auto [u, b] = q.front();
          q.pop();

          for (const int& v : graph[u]) {
            int p = b | (1 << v);
            if (p == N - 1)
              return res;
            else if (!dp[v][p]) {
              dp[v][p] = true;
              q.emplace(v, p);
            }
          }
        }

        ++res;
      }
      

      return 0;
    }
};


int main() {
  EXECS(Solution::shortestPathLength);
  return 0;
}