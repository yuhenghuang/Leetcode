#include "utils3.hpp"

class Solution {
  public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
      // O(n * m * 2^m)

      // coin counts
      vector<int> count;

      int uid = 0;
      // unique number, index
      unordered_map<int, int> num2idx;
      for (int num : nums) {
        auto iter = num2idx.find(num);

        // found new unique number
        if (iter == num2idx.end()) {
          num2idx[num] = uid++;
          count.push_back(1);
        }
        else
          ++count[iter->second];
      }

      const int n = count.size();
      const int m = quantity.size();
      const int M = 1 << m;

      // coin, combination of customers
      int dp[n+1][M];
      for (int i = 0; i <= n; ++i)
        for (int j = 0; j < M; ++j)
          dp[i][j] = INT_MAX;


      dp[0][0] = 0;
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < M; ++j) {
          if (dp[i][j] == INT_MAX) continue;

          // indicating NOT able to satisfy more customers using current coin
          bool flag = true;

          for (int k = 0; k < m; ++k)
            if (((1 << k) & j) == 0 && dp[i][j] + quantity[k] <= count[i]) {
              flag = false;
              // start from next coin
              if (dp[i][j] + quantity[k] == count[i])
                dp[i+1][j | (1 << k)] = 0;
              // stay at current coin, update forthcoming combinations
              else
                dp[i][j | (1 << k)] = min(dp[i][j | (1 << k)], dp[i][j] + quantity[k]);
            }

          // move to next coin, start freshly
          // this helps move dp[i][M-1] to dp[n][M-1] also
          if (flag)
            dp[i+1][j] = 0;
        }

      return dp[n][M-1] != INT_MAX;
    }
};


int main() {
  UFUNCS(Solution::canDistribute);
  return 0;
}