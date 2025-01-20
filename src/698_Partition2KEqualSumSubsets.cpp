#include <numeric>
#include "utils2.hpp"


class Solution {
  public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
      int target = accumulate(nums.begin(), nums.end(), 0);

      if (target % k)
        return false;

      target /= k;

      int n = nums.size();
      int N = 1 << n;

      bool dp[N];
      int memo[N];
      memset(dp, 0, N);

      dp[0] = true;
      memo[0] = 0;
      for (int i=0; i<N; ++i) {
        if (!dp[i]) continue;

        for (int j=0; j<n; ++j) {
          int i_next = i | (1 << j);
          if (i==i_next || dp[i_next]) continue;

          int m_next = memo[i] + nums[j];

          if (m_next<=target) {
            dp[i_next] = true;
            memo[i_next] = m_next % target;
          }
        }
      }

      return dp[N-1];
    }
};


int main() {
  UFUNC(Solution::canPartitionKSubsets);
  return 0;
}