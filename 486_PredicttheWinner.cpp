#include <local_leetcode.hpp>

class Solution {
  public:
    bool PredictTheWinner(vector<int>& nums) {
      const int n = nums.size();

      int dp[n][n];
      for (int i = 0; i < n; ++i)
        dp[i][i] = nums[i];

      for (int l = 1; l < n; ++l)
        for (int i = 0, j = l; j < n; ++i, ++j) 
          dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);

      return dp[0][n-1] >= 0;
    }
};


int main() {
  EXECS(Solution::PredictTheWinner);
  return 0;
}