#include "utils3.hpp"

class Solution {
  public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
      int m = mat.size(), n = m==0 ? 0 : mat[0].size();

      vector<vector<int>> res(m, vector<int>(n, 10000));

      if (mat[0][0] == 0)
        res[0][0] = 0;

      for (int i = 1; i < m; ++i)
        res[i][0] = mat[i][0] ? res[i-1][0] + 1 : 0;

      for (int j = 1; j < n; ++j)
        res[0][j] = mat[0][j] ? res[0][j-1] + 1 : 0;

      for (int i = 1; i < m; ++i)
        for (int j = 1; j < n; ++j)
          res[i][j] = mat[i][j] ? min(res[i-1][j], res[i][j-1]) + 1 : 0;

      for (int i = m - 2; i >= 0; --i)
        if (mat[i][n-1])
          res[i][n-1] = min(res[i][n-1], res[i+1][n-1] + 1);

      for (int j = n - 2; j >= 0; --j)
        if (mat[m-1][j])
          res[m-1][j] = min(res[m-1][j], res[m-1][j+1] + 1);

      for (int i = m - 2; i >= 0; --i)
        for (int j = n - 2; j >= 0; --j)
          res[i][j] = min(res[i][j], min(res[i+1][j], res[i][j+1]) + 1);

      return res;
    }

    vector<vector<int>> updateMatrixBFS(vector<vector<int>>& mat) {
      int m = mat.size(), n = m==0 ? 0 : mat[0].size();

      queue<pair<int, int>> q;
      vector<vector<int>> res(m, vector<int>(n, -1));

      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (mat[i][j] == 0) {
            q.emplace(i, j);
            res[i][j] = 0;
          }

      int dist = 1;
      vector<vector<int>> dirs{{1,0}, {0,1}, {-1,0}, {0,-1}};
      while (!q.empty()) {
        int N = q.size();
        while (N--) {
          auto& p = q.front();
          for(auto& d : dirs) {
            int i = p.first + d[0];
            int j = p.second + d[1];
            if (i >= 0 && i < m && j >= 0 && j < n && res[i][j] < 0) {
              q.emplace(i, j);
              res[i][j] = dist;
            }
          }
          q.pop();
        }
        ++dist;
      }

      return res;
    }
};


int main() {
  UFUNCS(Solution::updateMatrix);
  UFUNCS(Solution::updateMatrixBFS);
  return 0;
}