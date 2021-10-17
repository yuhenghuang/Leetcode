#include "utils3.hpp"

class Solution {
  public:
    int maxValue(vector<vector<int>>& events, int k) {
      sort(
        events.begin(), 
        events.end(),
        [](vector<int>& x, vector<int>& y) { return x[1] < y[1]; }
      );

      vector<map<int, int, greater<int>>> dp(k + 1);
      for (auto& m : dp)
        m[0] = 0;

      for (auto & e : events)
        for (int i = 1; i <= k; ++i) {
          int val = dp[i - 1].upper_bound(e[0])->second + e[2];
          if (val > dp[i].begin()->second)
            dp[i][e[1]] = val;
        }

      return dp.back().begin()->second;
    }
};


int main() {
  UFUNCS(Solution::maxValue);
  return 0;
}