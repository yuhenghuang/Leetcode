#include <local_leetcode.hpp>

class Solution {
  public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& suppliers) {
      sort(packages.begin(), packages.end());

      for (auto& boxes : suppliers)
        sort(boxes.begin(), boxes.end());

      int n = packages.size();

      vector<long> prefix(n + 1);
      for (int i = 0; i < n; ++i)
        prefix[i+1] = prefix[i] + packages[i];

      long res = LONG_MAX;

      for (auto& boxes : suppliers) {
        long waste = 0;

        int i = 0;
        auto it = packages.begin();
        // use long to avoid int overflow (1e5 * 1e5)
        for (long box : boxes) {
          // move left bound forward to narrow down search space
          it = upper_bound(it, packages.end(), (int) box);

          // the index in packages that is larger than box
          int j = it - packages.begin();

          waste += (j - i) * box - (prefix[j] - prefix[i]);

          i = j;

          // early stop
          if (i == n)
            break;
        }

        // all packages packed.
        if (i == n && waste < res)
          res = waste;
      }

      constexpr long mod = 1e9 + 7;

      return res == LONG_MAX ? -1 : res % mod;
    }
};


int main() {
  EXECS(Solution::minWastedSpace);
  return 0;
}