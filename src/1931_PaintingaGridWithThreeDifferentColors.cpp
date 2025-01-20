#include <local_leetcode.hpp>

class Solution {
  private:
    void dfs(int bits, int m, vector<int>& cols) {
      if (m == 0) {
        cols.push_back(bits);
        return;
      }

      for (int j = 0; j < 3; ++j)
        if ((bits & (1 << j)) == 0)
          dfs((bits << 3) | (1 << j), m - 1, cols);
    }

  public:
    int colorTheGrid(int m, int n) {
      constexpr int mod = 1e9 + 7;

      // 1 cell = 3 bits
      // three colors = 001, 010, 100

      // valid bits representations of ONE column
      vector<int> cols;

      dfs(0, m, cols);

      int p = cols.size();
      vector<vector<int>> graph(p);
      for (int i = 1; i < p; ++i)
        for (int j = 0; j < i; ++j)
          if ((cols[i] & cols[j]) == 0) {
            graph[i].push_back(j);
            graph[j].push_back(i);
          }

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


int main() {
  EXECS(Solution::colorTheGrid);
  return 0;
}