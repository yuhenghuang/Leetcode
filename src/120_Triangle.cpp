#include <local_leetcode.hpp>

class Solution {
  public:
    int minimumTotal(vector<vector<int>>& triangle) {
      int n = triangle.size();
      
      vector<int> dp = triangle.back();

      for (int i = n - 2; i >= 0; --i)
        for (int j = 0; j <= i; ++j)
          dp[j] = min(dp[j+1], dp[j]) + triangle[i][j];

      return dp[0];
    }

    int minimumTotalOld(vector<vector<int>>& triangle) {
      int n = triangle.size();
      for (int i = n-2; i >= 0; --i)
        for (int j = 0; j <= i; ++j)
          triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);

      return triangle[0][0];
    }
};


int main() {
  EXECS(Solution::minimumTotal);
  EXECS(Solution::minimumTotalOld);
  return 0;
}