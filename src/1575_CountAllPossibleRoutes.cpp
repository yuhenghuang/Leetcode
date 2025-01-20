#include <local_leetcode.hpp>

class Solution {
  public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
      constexpr int mod = 1e9 + 7;

      const int n = locations.size();

      int distance[n][n];
      for (int i = 0; i < n; ++i) {
        // not staying the same place in a round
        distance[i][i] = fuel + 1;
        for (int j = 0; j < i; ++j)
          distance[i][j] = distance[j][i] = abs(locations[i] - locations[j]);
      }

      int dp[fuel+1][n];
      memset(dp, 0, sizeof(dp));

      dp[fuel][start] = 1;
      for (int f = fuel; f > 0; --f)
        for (int i = 0; i < n; ++i) {
          if (dp[f][i] == 0) continue;

          // possible improvement: sort locations to reduce loops here
          // only search locations within radius (current fuel)
          for (int j = 0; j < n; ++j) {
            int g = f - distance[i][j];
            if (g >= 0) 
              dp[g][j] = (dp[g][j] + dp[f][i]) % mod;
          }
        }

      int res = 0;
      for (int f = 0; f <= fuel; ++f)
        res = (res + dp[f][finish]) % mod;

      return res;
    }
};


int main() {
  EXECS(Solution::countRoutes);
  return 0;
}