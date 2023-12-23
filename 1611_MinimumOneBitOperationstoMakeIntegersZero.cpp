#include <local_leetcode.hpp>

class Solution {
  private:
    static int dp[31];

    static bool __helper;

    static bool init() {
      /* example 000 -> 100
        000
        001
        011
        010
        110
        111
        101
        100
      */

      dp[0] = 0;
      for (int i = 1; i < 31; ++i)
        // to modify bit i and restore zeros between [0, i - 1]
        // one need to
        // 1. modify bit i-1 to 1 (dp[i-1])
        // 2. modify bit 1 (1)
        // 3. modify bit i-1 to 0 (dp[i-1])
        dp[i] = 1 + (dp[i - 1] * 2);

      return true;
    }

  public:
    int minimumOneBitOperations(int n) {
      if (n == 0)
        return 0;

      const int m = std::numeric_limits<int>::digits - __builtin_clz(n) + 1; // num. of bits of the number

      int memo[32][2]; // position of bit where all right bits are 0 (1-base), bit itself being 0 or 1 -> minimal ops

      memo[0][0] = memo[0][1] = 0;
      for (int i = 1; i <= m; ++i) {
        int b = (n >> (i - 1)) & 1;

        memo[i][b] = memo[i-1][0]; // no change in b

        // case 1: bit i-1 is already 1 and [0, i-2] being 0
        // modify bit i with 1 ops, and modify bit i-1 with dp[i-1] ops
        // b1 -> (1-b)1 -> (1-b)0

        // case 2: bit i-1 is still 0 and [0, i-2] being 0
        // modify bit i with dp[i] ops
        // b0 -> b1 -> (1-b)1 -> (1-b)0

        // memo[i][1 - b] = min(memo[i-1][1] + 1 + dp[i-1], memo[i-1][0] + dp[i]);

        // further optimization
        // dp[i] = (1 << i) - 1
        memo[i][1 - b] = min(memo[i-1][1] + (1 << (i - 1)) /*- 1 + 1*/, memo[i-1][0] + (1 << i) - 1);
      }

      return memo[m][0];
    }
};

int Solution::dp[];
bool Solution::__helper = Solution::init();


int main() {
  EXECS(Solution::minimumOneBitOperations);
  return 0;
}