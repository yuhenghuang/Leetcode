#include <numeric>
#include "utils3.hpp"

class Solution {
  public:
    int minCut(string s) {
      const int n = s.size();
      vector<int> dp(n+1, INT_MAX);
      dp[0] = 0;

      // totally 2 * n - 1 centers
      for (int i = 0; i < 2 * n - 1; ++i) {
        int j = i / 2;
        int k = j + i % 2;

        while (j >= 0 && k < n && s[j--] == s[k++])
          dp[k] = min(dp[k], dp[j+1] + 1);
      }

      return dp[n] - 1;
    }
};


int main() {
  UFUNCS(Solution::minCut);
  return 0;
}