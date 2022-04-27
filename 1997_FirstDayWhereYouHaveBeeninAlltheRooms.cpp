#include <local_leetcode.hpp>

class Solution {
  public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
      constexpr int mod = 1e9 + 7;

      int n = nextVisit.size();

      vector<int> dp(n);
      for (int i = 0; i < n - 1; ++i) 
        dp[i+1] = (dp[i] + ((dp[i] - dp[nextVisit[i]] + mod + 2) % mod)) % mod;

      return dp.back();
    }
};


int main() {
  EXECS(Solution::firstDayBeenInAllRooms);
  return 0;
}