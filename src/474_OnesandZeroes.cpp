#include <local_leetcode.hpp>

class Solution {
  public:
    int findMaxForm(vector<string>& strs, int m, int n) {
      vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

      dp[0][0] = 0;
      for (auto& s : strs) {
        int w = 0; // zero count
        int h = 0; // one count

        for (char c : s)
          if (c == '0')
            ++w;
          else
            ++h;

        for (int i = m; i >= w; --i)
          for (int j = n; j >= h; --j)
            if (dp[i - w][j - h] != -1)
              dp[i][j] = max(dp[i][j], dp[i - w][j - h] + 1);
      }
      
      int res = 0;

      // can be further optimized? maybe not...
      for (auto& row : dp)
        for (const int& ele : row)
          if (ele > res)
            res = ele;

      return res;
    }
};


int main() {
  EXECS(Solution::findMaxForm);
  return 0;
}