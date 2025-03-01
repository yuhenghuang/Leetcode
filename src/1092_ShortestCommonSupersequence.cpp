#include <local_leetcode.hpp>

#define N 1001

class Solution {
  private:
    static int16_t dp[N][N];
    static bool helper;

    static bool init() {

      // initialize first row
      for (int i = 0; i < N; ++i)
        dp[0][i] = i;

      // initialize first column
      for (int j = 1; j < N; ++j)
        dp[j][0] = j;
      
      return true;
    }

  public:
    string shortestCommonSupersequence(string str1, string str2) {
      const int m = str1.size();
      const int n = str2.size();

      for (int i = 1; i <= m; ++i) 
        for (int j = 1; j <= n; ++j)
          if (str1[i-1] == str2[j-1])
            dp[i][j] = dp[i-1][j-1] + 1;
          else
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;

      string res;

      int i = m, j = n;
      while (i > 0 and j > 0) {
        if (str1[i-1] == str2[j-1]) {
          res.push_back(str1[i-1]);
          --i;
          --j;
        }
        else {
          if (dp[i-1][j] < dp[i][j-1]) {
            res.push_back(str1[i-1]);
            --i;
          }
          else {
            res.push_back(str2[j-1]);
            --j;
          }
        }
      }

      for (; i > 0; --i)
        res.push_back(str1[i-1]);
      
      for (; j > 0; --j)
        res.push_back(str2[j-1]);

      reverse(res.begin(), res.end());

      return res;
    }
};

int16_t Solution::dp[N][N];
bool Solution::helper = Solution::init();

int main() {
  EXECS(Solution::shortestCommonSupersequence);
  return 0;
}