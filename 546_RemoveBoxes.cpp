#include "utils3.hpp"

class Solution {
  private:
    int dfs(int i, int j, int k, vector<int>& boxes, vector<vector<vector<int>>>& dp) {
      if (i > j) return 0;
      else if (dp[i][j][k] > 0) return dp[i][j][k];

      int res = (k+1) * (k+1) + dfs(i+1, j, 0, boxes, dp);
      for (int m = i + 1; m <= j; ++m)
        if (boxes[i] == boxes[m])
          res = max(res, dfs(i+1, m-1, 0, boxes, dp) + dfs(m, j, k+1, boxes, dp));

      return dp[i][j][k] = res;
    }

  public:
    int removeBoxes(vector<int>& boxes) {
      int n = boxes.size();
      vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n)));

      return dfs(0, n-1, 0, boxes, dp);
    }
};


int main() {
  UFUNCS(Solution::removeBoxes);
  return 0;
}