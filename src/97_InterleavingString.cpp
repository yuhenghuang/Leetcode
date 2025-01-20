#include <local_leetcode.hpp>

class Solution {
  public:
    bool isInterleave(string s1, string s2, string s3) {
      int m = s1.size(), n = s2.size();
      if (m+n != s3.size())
        return false;

      bool memo[m+1][n+1];
      memset(memo, 0, (m+1)*(n+1));
      memo[0][0] = true;

      for (int i=0; i<m; ++i)
        memo[i+1][0] = memo[i][0] && s1[i]==s3[i];

      for (int j=0; j<n; ++j)
        memo[0][j+1] = memo[0][j] && s2[j]==s3[j];

      for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j) 
          memo[i+1][j+1] = (memo[i][j+1] && s1[i]==s3[i+j+1]) || (memo[i+1][j] && s2[j]==s3[i+j+1]);

      return memo[m][n];
    }
};


int main() {
  EXECS(Solution::isInterleave);
  return 0;
}
