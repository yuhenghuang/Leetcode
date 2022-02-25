#include <local_leetcode.hpp>

class Solution {
  public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
      int n = nums1.size();

      int N = 1 << n;

      vector<int> dp(N, INT_MAX);
      dp.front() = 0;

      for (int b = 1; b < N; ++b) {
        int i = __builtin_popcount(b) - 1;

        for (int j = 0; j < n; ++j)
          if ((b >> j) & 1)
            dp[b] = min(dp[b], dp[b ^ (1 << j)] + (nums1[i] ^ nums2[j]));
      }

      return dp.back();
    }
};


int main() {
  EXECS(Solution::minimumXORSum);
  return 0;
}