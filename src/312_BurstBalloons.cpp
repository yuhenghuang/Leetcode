#include "utils.hpp"

class Solution {
  public:
    int maxCoins(vector<int>& nums) {
      nums.insert(nums.begin(), 1);
      nums.push_back(1);

      int n = nums.size();
      int dp[n][n];
      memset(dp, 0, n*n*sizeof(int));

      // windows is [j, j+i] inclusively
      // loop inside window [j+1, j+i-1] inclusively
      for (int i=2; i<n; ++i)
        for (int j=0; j+i<n; ++j)
          for (int k=1; k<i; ++k)
            dp[j][j+i] = max(dp[j][j+i], nums[j] * nums[j+i] * nums[j+k] + dp[j][j+k] + dp[j+k][j+i]);

      return dp[0][n-1];
    }
};


int main() {
  UFUNC(Solution::maxCoins);
  return 0;
}