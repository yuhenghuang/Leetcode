#include <local_leetcode.hpp>

class Solution {
  public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
      const int m = matrix.size();
      const int n = matrix[0].size();

      vector<int> height(n);
      map<int, int, greater<>> count; // height, count of columns

      int res = 0;
      for (int i = 0; i < m; ++i) {
        count.clear();
        for (int j = 0; j < n; ++j) {
          if (matrix[i][j])
            ++height[j];
          else
            height[j] = 0;

          ++count[height[j]];
        }

        int cum_count = 0;
        for (auto [h, c] : count) {
          cum_count += c;

          res = max(res, h * cum_count);
        }
      }

      return res;
    }
};


int main() {
  EXECS(Solution::largestSubmatrix);
  return 0;
}