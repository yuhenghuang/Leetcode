#include <local_leetcode.hpp>

class Solution {
  private:
    static vector<vector<int>> graph;

    static void dfs(int bits, int m, vector<int>& cols) {
      if (m == 0) {
        cols.push_back(bits);
        return;
      }

      for (int j = 0; j < 3; ++j)
        if ((bits & (1 << j)) == 0)
          dfs((bits << 3) | (1 << j), m - 1, cols);
    }

    static vector<vector<int>> initGraph() {
      vector<int> cols;
      dfs(0, 3, cols);

      vector<vector<int>> graph(cols.size());
      for (int i = 1; i < cols.size(); ++i)
        for (int j = 0; j < i; ++j)
          if ((cols[i] & cols[j]) == 0) {
            graph[i].push_back(j);
            graph[j].push_back(i);
          }

      return graph;
    }

  public:
    int numOfWays(int n) {
      constexpr int mod = 1e9 + 7;
      int p = graph.size();

      vector<int> curr(p, 1);
      vector<int> next(p);

      for (int i = 1; i < n; ++i) {
        for (int u = 0; u < p; ++u)
          for (const int& v : graph[u]) 
            next[v] = (next[v] + curr[u]) % mod;

        swap(curr, next);
        next.assign(p, 0);
      }

      int res = 0;
      for (int u = 0; u < p; ++u)
        res = (res + curr[u]) % mod;

      return res;
    }
};

vector<vector<int>> Solution::graph = Solution::initGraph();


int main() {
  EXECS(Solution::numOfWays);
  return 0;
}