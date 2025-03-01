#include <local_leetcode.hpp>

#define N 1000

class Solution {
  private:
    static int16_t dp[N][N];

  public:
    int lenLongestFibSubseq(vector<int>& arr) {
      const int n = arr.size();

      // only reseting first n row would be sufficient 
      memset(dp, 0, sizeof(int16_t) * N * n);

      int16_t res = 0;
      for (int k = 2; k < n; ++k) {
        for (int i = 0, j = k - 1; i < j; --j) {
          int num = arr[k] - arr[j];

          for (; arr[i] < num; ++i);

          if (arr[i] == num) {
            dp[j][k] = max<int16_t>(dp[j][k], max<int16_t>(dp[i][j], 2) + 1);
            res = max(res, dp[j][k]);
          }
        }
      }

      return res;
    }
};

int16_t Solution::dp[N][N];

int main() {
  EXECS(Solution::lenLongestFibSubseq);
  return 0;
}