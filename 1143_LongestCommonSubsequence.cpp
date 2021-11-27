#include "utils3.hpp"

class Solution {
  public:
    int longestCommonSubsequence(string text1, string text2) {
      int m = text1.length(), n = text2.length();
      int memo[m+1][n+1];
      memset(memo, 0, (m+1)*(n+1)*sizeof(int));
      for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
          if (text1.at(i-1)==text2.at(j-1))
            memo[i][j] = memo[i-1][j-1] + 1;
          else
            memo[i][j] = max(memo[i][j-1], memo[i-1][j]);
      return memo[m][n];
    }
};

int main() {
  UFUNCS(Solution::longestCommonSubsequence);
  return 0;
}