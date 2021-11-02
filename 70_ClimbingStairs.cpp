#include "utils3.hpp"

class Solution {
  public:
    int climbStairs(int n) {
      int memo[n+1];
      memo[0] = 1;
      memo[1] = 1;
      for (int i=2; i<=n; ++i)
        memo[i] = memo[i-1] + memo[i-2];
      return memo[n];
    }
};

int main() {
  UFUNCS(Solution::climbStairs);
  return 0;
}
