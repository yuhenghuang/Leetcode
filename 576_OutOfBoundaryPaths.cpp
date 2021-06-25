#include "utils2.hpp"

class Solution {
  private:
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
  public:
    int findPaths(int m, int n, int N, int i, int j) {
      vector<vector<long>> mat(m, vector<long>(n, 0));
      mat[i][j] = 1;
      long mod = 1e9 + 7;
      long res = 0;

      while (N--) {
        // copy(mat[0].begin(), mat[0].end(), ostream_iterator<long>(cout, ", "));
        vector<vector<long>> mat_next(m, vector<long>(n, 0));
        for (int row=0; row<m; ++row)
          for (int clm=0; clm<n; ++clm)
            for (int k=0; k<4; ++k) {
              int r = row + dir[k][0], c = clm + dir[k][1];
              if (r<0 || r>=m || c<0 || c>=n) {
                res += mat[row][clm];
                res %= mod;
              }
              else {
                mat_next[r][c] += mat[row][clm];
                mat_next[r][c] %= mod;
              }
            }
        mat = mat_next;
      }
      return res;
    }

    int findPaths1D(int m, int n, int t, int i, int j) {
      constexpr int mod = 1e9 + 7;
      const vector<vector<int>> dirs {{1,0}, {-1,0}, {0,1}, {0,-1}};

      int N = m * n;
      vector<int> dp(N), dp_prime(N);
      dp[i * n + j] = 1;

      int res = 0;
      while (t--) {
        for (int k = 0; k < N; ++k) {
          i = k / n;
          j = k % n;
          for (const vector<int>& d : dirs) {
            int ii = i + d[0];
            int jj = j + d[1];
            if (ii < 0 || ii == m || jj < 0 || jj == n) {
              res = (res + dp[k]) % mod;
            }
            else {
              int kk = ii * n + jj;
              dp_prime[kk] = (dp_prime[kk] + dp[k]) % mod;
            }
          }
        }

        swap(dp, dp_prime);
        dp_prime.assign(N, 0);
      };

      return res;
    }
};


int main() {
  {
    UFUNC(Solution::findPaths);
  }
  {
    UFUNC(Solution::findPaths1D);
  }
  return 0;
}