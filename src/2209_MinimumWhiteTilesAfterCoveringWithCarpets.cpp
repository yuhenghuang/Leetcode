#include <local_leetcode.hpp>

class Solution {
  public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
      int n = floor.size();

      vector<int> prefix(n + 1);
      for (int i = 0; i < n; ++i)
        prefix[i+1] = prefix[i] + (floor[i] - '0');

      vector<vector<int>> dp(n + 1, vector<int>(numCarpets + 1));

      for (int i = 1; i <= n; ++i) {
        int j = max(0, i - carpetLen);
        int d = prefix[i] - prefix[j];

        for (int k = 1; k <= numCarpets; ++k)
          dp[i][k] = max(dp[i-1][k], dp[j][k-1] + d);
      }

      return prefix[n] - dp[n][numCarpets];
    }
};


int main() {
  EXECS(Solution::minimumWhiteTiles);
  return 0;
}