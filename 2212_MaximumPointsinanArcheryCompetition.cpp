#include <local_leetcode.hpp>

class Solution {
  private:
    static const int n;
    static constexpr int N = 1 << 12;

    static int points[N];

    static int init() {
      points[0] = 0;

      for (int i = 1; i < N; ++i) {
        int b = __builtin_ctz(i);

        points[i] = points[i ^ (1 << b)] + b;
      }

      return 12;
    }

  public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
      int res = -1; // result in bits
      int p = -1; // current max point

      int dp[N];
      memset(dp, -1, sizeof(dp));
      dp[0] = numArrows;

      for (int i = 1; i < N; ++i) {
        // use least arrows to win sections marked by bits of i
        for (int j = 0; j < n; ++j)
          if ((i >> j) & 1) 
            dp[i] = max(dp[i], dp[i ^ (1 << j)] - aliceArrows[j] - 1);

        if (dp[i] >= 0 && points[i] > p) {
          p = points[i];
          res = i;
        }
      }

      vector<int> ans(12);
      for (int i = 0; i < n; ++i)
        if ((res >> i) & 1) 
          numArrows -= ans[i] = aliceArrows[i] + 1;

      // or simply add to ans[0] ?
      auto iter = find(ans.begin(), ans.end(), 0);
      *iter = numArrows;

      return ans;
    }
};

int Solution::points[];

const int Solution::n = Solution::init();


int main() {
  EXECS(Solution::maximumBobPoints);
  return 0;
}