#include <algorithm>
#include <numeric>
#include "utils3.hpp"

class Solution {
  private:
    vector<int>& dfs(int n, unordered_map<int, vector<int>>& dp) {
      if (dp.count(n) > 0)
        return dp[n];

      vector<int> res(n);
      const vector<int>& v1 = dfs((n+1)/2, dp);
      const vector<int>& v2 = dfs(n/2, dp);

      transform(
        v2.begin(), v2.end(),
        transform(
          v1.begin(),
          v1.end(),
          res.begin(),
          [](int val) { return val * 2 - 1; }
        ),
        [](int val) { return val * 2; }
      );

      return dp[n] = res;
    }

  public:
    vector<int> beautifulArray(int n) {
      unordered_map<int, vector<int>> dp;
      dp.emplace(1, vector<int> {1});
      return dfs(n, dp);
    }
};


int main() {
  UFUNCS(Solution::beautifulArray);
  return 0;
}