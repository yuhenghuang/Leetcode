#include <local_leetcode.hpp>

class Solution {
  public:
    bool isScramble(string s1, string s2) {
      int n = s1.size();
      if (n != s2.size())
        return false;

      bool dp[n][n][n];
      for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
          dp[i][j][0] = s1[i] == s2[j];

      for (int l=1; l<n; ++l)
        for (int i=0; i+l<n; ++i)
          for (int j=0; j+l<n; ++j)
            for (int k=0; k<l; ++k) {
              dp[i][j][l] = (dp[i][j][k] && dp[i+k+1][j+k+1][l-k-1]) ||
                            (dp[i][j+l-k][k] && dp[i+k+1][j][l-k-1]);

              if (dp[i][j][l])
                break;
            }

      return dp[0][0][n-1];
    }
};


int main() {
  EXECS(Solution::isScramble);
  return 0;
}