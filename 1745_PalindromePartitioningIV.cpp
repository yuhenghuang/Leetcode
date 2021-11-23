#include "utils3.hpp"

class Solution {
  public:
    bool checkPartitioning(string s) {
      const int n = s.size();

      bool dp[n][n];

      dp[0][0] = true;

      for (int i = 1; i < n; ++i){
        dp[i][i-1] = true;
        dp[i][i] = true;
      }

      for (int k = 1; k < n; ++k)
        for (int i = 0; i + k < n; ++i)
          dp[i][i+k] = s[i] == s[i+k] && dp[i+1][i+k-1];


      for (int i = 0; i < n - 2; ++i)
        for (int j = i + 2; j < n; ++j)
          if (dp[0][i] && dp[i+1][j-1] && dp[j][n-1])
            return true;
      
      return false;
    }
};


int main() {
  UFUNCS(Solution::checkPartitioning);
  return 0;
}