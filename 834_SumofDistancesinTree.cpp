#include <vector>

using namespace std;

class Solution {
  private:
    vector<vector<int>> memo, graph, memo2;
    vector<int> res;
  public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
      memo = vector<vector<int>>(N, vector<int>(N, 0));
      memo2 = vector<vector<int>>(N, vector<int>(N, 0));
      graph = vector<vector<int>>(N);
      res = vector<int>(N, 0);

      for (auto e : edges) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
      }

      for (int i=0; i<N; i++)
        for (int j : graph[i])
          dfs(i, j);

      for (int i=0; i<N; i++)
        for (int j : graph[i])
          dp(i, j);
      
      for (int i=0; i<N; i++) 
        for (int v : graph[i])
          res[i]+=memo2[i][v];
      return res;
    }

    int dp(int v, int w) {
      if (memo2[v][w]>0) return memo2[v][w];

      for (int n : graph[w]) {
        if (n==v) continue;
        memo2[v][w] += (1+memo[v][w])+dp(w, n);
      }
      return memo2[v][w];
    }

    int dfs(int v, int w) {
      if (memo[v][w]>0) return memo[v][w];

      for (int n : graph[w]) {
        if (n==v) continue;
        memo[v][w] += 1+dfs(w, n);
      }
      return memo[v][w];
    }
};