#include "utils3.hpp"

class Solution {
  public:
    int maxTwoEvents(vector<vector<int>>& events) {
      int n = events.size();

      sort(events.begin(), events.end());

      vector<int> dp(n + 1);
      for (int i = n-1; i >= 0; --i)
        dp[i] = max(dp[i+1], events[i][2]);

      auto cmp = [](int x, const vector<int>& y) {
        return x < y[0];
      };

      int res = 0;
      for (auto i = events.begin(); i != events.end(); ++i) {
        int j = upper_bound(i+1, events.end(), i->at(1), cmp) - events.begin();

        int val = i->at(2) + dp[j];

        if (val > res)
          res = val;
      }

      return res;
    }
};


int main() {
  UFUNCS(Solution::maxTwoEvents);
  return 0;
}