#include <local_leetcode.hpp>

class Solution {
  public:
    long long maxPoints(vector<vector<int>>& points) {
      // O(m * 2n)

      int m = points.size();
      int n = points[0].size();

      vector<long> curr(points[0].begin(), points[0].end());
      vector<long> next(n);

      for (int i = 1; i < m; ++i) {
        long temp = 0;
        for (int j = 0; j < n; ++j) {
          temp = max(temp - 1, curr[j]);
          next[j] = temp + points[i][j];
        }

        temp = 0;
        for (int j = n - 1; j >= 0; --j) {
          temp = max(temp - 1, curr[j]);
          next[j] = max(next[j], temp + points[i][j]);
        }

        // O(1)
        swap(curr, next);

        // for (j = 0; j < n; ++j)
        //   curr[j] += points[i][j];
      }

      return *max_element(curr.begin(), curr.end());
    }
};


int main() {
  EXECS(Solution::maxPoints);
  return 0;
}