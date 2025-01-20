#include "utils2.hpp"

class Solution {
  public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
      int m = matrix.size();
      int n = matrix[0].size();

      int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

      vector<vector<int>> graph(m*n);
      vector<int> indegree(m*n);

      for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
          for (int k=0; k<4; ++k) {
            int p = i + dirs[k][0];
            int q = j + dirs[k][1];
            if (p>=0 && p<m && q>=0 && q<n && matrix[p][q] > matrix[i][j]) {
              graph[i*n + j].push_back(p*n + q);
              ++indegree[p*n + q];
            }
          }

      queue<int> q;
      for (int i=0 ; i<m*n; ++i)
        if (indegree[i] == 0)
          q.push(i);

      int res = 0;
      while (!q.empty()) {
        int N = q.size();
        while (N--) {
          int v = q.front(); q.pop();
          for (int w : graph[v])
            if (--indegree[w] == 0)
              q.push(w);
        }

        ++res;
      }

      return res;
    }
};


int main() {
  UFUNC(Solution::longestIncreasingPath);
  return 0;
}