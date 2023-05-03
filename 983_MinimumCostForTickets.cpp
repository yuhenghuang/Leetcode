#include <local_leetcode.hpp>

class Solution {
  public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
      // O(n), n = max value of days

      int n = days.back();

      int dp[n + 1];
      dp[0] = 0;

      int units[3] = {1, 7, 30};

      int j = 0;
      for (int i = 1; i <= n; ++i) {
        if (i < days[j])
          dp[i] = dp[i-1];
        else {
          ++j;
          int res = INT_MAX;

          for (int k = 0; k < 3; ++k)
            res = min(res, costs[k] + dp[max(0, i - units[k])]);

          dp[i] = res;
        }
      }

      return dp[n];
    }

    int mincostTicketsOp(vector<int>& days, vector<int>& costs) {
      // optimized version
      // O(n), n = size of days

      int n = days.size();
      int dp[n];

      constexpr int units[3] = {1, 7, 30};

      int js[3] = {0};

      for (int i = 0; i < n; ++i) {
        int res = INT_MAX;
        for (int k = 0; k < 3; ++k) {
          int& j = js[k];
          for (; days[j] <= days[i] - units[k]; ++j);

          res = min(res, (j > 0 ? dp[j - 1] : 0) + costs[k]);
        }

        dp[i] = res;
      }

      return dp[n-1];
    }
};


int main() {
  EXECS(Solution::mincostTickets);
  EXECS(Solution::mincostTicketsOp);
  return 0;
}