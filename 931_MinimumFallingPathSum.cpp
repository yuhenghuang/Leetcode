#include <local_leetcode.hpp>

class Solution {
  public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
      int n = matrix.size();

      vector<int> prev(n + 2), curr(n + 2);

      prev[0] = curr[0] = prev[n+1] = curr[n+1] = INT_MAX;
      copy(matrix.front().begin(), matrix.front().end(), prev.begin() + 1);


      for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= n; ++j)
          curr[j] = min(min(prev[j-1], prev[j+1]), prev[j]) + matrix[i][j-1];

        swap(prev, curr);
      }

      return *min_element(prev.begin(), prev.end());
    }
};


int main() {
  EXECS(Solution::minFallingPathSum);
  return 0;
}