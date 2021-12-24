#include <local_leetcode.hpp>

class Solution {
  public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
      int n = security.size();
      vector<int> dp(n);
      for (int i = n - 2; i >= 0; --i)
        if (security[i+1] >= security[i])
          dp[i] = dp[i+1] + 1;

      int l;
      vector<int> res;
      for (int i = 0; i < n; ++i) {
        if (i > 0 && security[i-1] >= security[i])
          ++l;
        else
          l = 0;

        if (l >= time && dp[i] >= time)
          res.push_back(i);
      }

      return res;
    }
};


int main() {
  EXECS(Solution::goodDaysToRobBank);
  return 0;
}