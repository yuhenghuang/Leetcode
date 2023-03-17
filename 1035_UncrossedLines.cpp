#include <local_leetcode.hpp>

class Solution {
  public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
      int m = nums1.size();
      int n = nums2.size();

      int dp[m+1][n+1];
      for (int i = 0; i <= m; ++i)
        dp[i][0] = 0;

      for (int j = 1; j <= n; ++j)
        dp[0][j] = 0;

      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
          if (nums1[i] == nums2[j])
            dp[i+1][j+1] = dp[i][j] + 1;
          else
            dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
        }

      return dp[m][n];
    }
};


int main() {
  EXECS(Solution::maxUncrossedLines);
  return 0;
}