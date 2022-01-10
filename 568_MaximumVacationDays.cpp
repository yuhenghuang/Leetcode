#include <local_leetcode.hpp>

class Solution {
  public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
      int n = flights.size(); // num. of cities
      int m = days[0].size(); // num. of weeks

      vector<int> curr(n, INT_MIN);
      vector<int> next(n, INT_MIN);

      curr[0] = 0;
      for (int k = 0; k < m; ++k) {
        for (int i = 0; i < n; ++i) {
          if (curr[i] == INT_MIN) continue;
          for (int j = 0; j < n; ++j)
            if (i == j || flights[i][j])
              next[j] = max(next[j], curr[i] + days[j][k]);
        }

        swap(curr, next);
        next.assign(n, INT_MIN);
      }

      return *max_element(curr.begin(), curr.end());
    }
};


int main() {
  EXECS(Solution::maxVacationDays);
  return 0;
}