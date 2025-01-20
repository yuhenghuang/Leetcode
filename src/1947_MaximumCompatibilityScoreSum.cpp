#include <local_leetcode.hpp>

class Solution {
  private:
    int m;
    int res;

    void dfs(int k, int s, vector<bool>& seen_s, vector<bool>& seen_m, vector<vector<int>>& mat) {
      if (k == m) {
        if (s > res)
          res = s;
        return;
      }

      for (int i = 0; i < m; ++i)
        if (!seen_s[i])
          for (int j = 0; j < m; ++j)
            if (!seen_m[j]) {
              seen_s[i] = seen_m[j] = true;

              dfs(k+1, s+mat[i][j], seen_s, seen_m, mat);

              seen_s[i] = seen_m[j] = false;
            }
    }

  public:
    int maxCompatibilitySumTLE(vector<vector<int>>& students, vector<vector<int>>& mentors) {
      m = students.size();
      int n = students[0].size();

      vector<vector<int>> mat(m, vector<int>(m));
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < m; ++j) {
          int score = 0;
          for (int k = 0; k < n; ++k)
            score += 1 ^ (students[i][k] ^ mentors[j][k]);

          mat[i][j] = score;
        }

      res = 0;

      vector<bool> seen_s(m), seen_m(m);
      dfs(0, 0, seen_s, seen_m, mat);

      return res;
    }

    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
      int m = students.size();
      int n = students[0].size();

      vector<vector<int>> mat(m, vector<int>(m));
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < m; ++j) {
          int score = 0;
          for (int k = 0; k < n; ++k)
            score += 1 ^ (students[i][k] ^ mentors[j][k]);

          mat[i][j] = score;
        }

      int M = 1 << m;
      int dp[M][M];
      memset(dp, 0, sizeof(dp));

      // dp[i][0] = 0
      // dp[0][j] = 0
      for (int bs = 1; bs < M; ++bs) {
        for (int bm = 1; bm < M; ++bm) {
          for (int i = 0; i < m; ++i)
            if (bs & (1 << i))
              for (int j = 0; j < m; ++j)
                if (bm & (1 << j)) 
                  dp[bs][bm] = max(dp[bs][bm], mat[i][j] + dp[bs ^ (1 << i)][bm ^ (1 << j)]);
        }
      }

      return dp[M-1][M-1];
    }

    int maxCompatibilitySumFast(vector<vector<int>>& students, vector<vector<int>>& mentors) {
      int m = students.size();
      int n = students[0].size();

      int mat[m][m];
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < m; ++j) {
          int score = 0;
          for (int k = 0; k < n; ++k)
            score += 1 ^ (students[i][k] ^ mentors[j][k]);

          mat[i][j] = score;
        }

      int M = 1 << m;
      
      int dp[M];
      memset(dp, 0, sizeof(dp));

      for (int b = 1; b < M; ++b) {
        int i = __builtin_popcount(b) - 1;
        for (int j = 0; j < m; ++j)
          if (b & (1 << j))
            dp[b] = max(dp[b], mat[i][j] + dp[b ^ (1 << j)]);
      }

      return dp[M-1];
    }
};


int main() {
  EXECS(Solution::maxCompatibilitySumTLE);
  EXECS(Solution::maxCompatibilitySum);
  EXECS(Solution::maxCompatibilitySumFast);
  return 0;
}