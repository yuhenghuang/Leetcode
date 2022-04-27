#include <local_leetcode.hpp>

class Solution {
  public:
    int minSessions(vector<int>& tasks, int sessionTime) {
      typedef pair<int, int> ii_t;

      const int n = tasks.size();

      const int N = 1 << n;

      // num. of sessiongs, remaining time
      vector<ii_t> dp(N);

      for (int i = 1; i < N; ++i) {
        ii_t p(INT_MAX, INT_MAX);
        for (int j = 0; j < n; ++j)
          if (i & (1 << j)) {
            ii_t q = dp[i ^ (1 << j)];

            if (q.second + tasks[j] > sessionTime) {
              ++q.first;
              q.second = tasks[j];
            }
            else
              q.second += tasks[j];

            p = min(p, q);
          }

        dp[i] = p;
      }

      ii_t& p = dp.back();
      return p.first + (p.second == 0 ? 0 : 1);
    }
};


int main() {
  EXECS(Solution::minSessions);
  return 0;
}