#include "utils3.hpp"

class Solution {
  public:
    int minTaps(int n, vector<int>& ranges) {
      typedef pair<int, int> pii;

      vector<pii> coverages;
      for (int i = 0; i <= n; ++i)
        if (ranges[i] > 0)
          coverages.push_back({max(0, i - ranges[i]), min(n, i + ranges[i])});

      // faster to use bucket sort for small n
      sort(coverages.begin(), coverages.end(),
        [](const pii& x, const pii& y) {
          return x.first == y.first ? x.second > y.second : x.first < y.first;
        }
      );

      int res = -1;
      // current reachable rightmost index
      int curr_tap = -1;
      // next reachable rightmost index
      int next_tap = 0;
      for (pii& p : coverages) {
        if (p.first > next_tap)
          return -1;

        if (p.first <= curr_tap) {
          next_tap = max(next_tap, p.second);
        }
        else {
          ++res;
          curr_tap = next_tap;
          next_tap = max(curr_tap, p.second);
        }

        // early stop
        if (next_tap >= n)
            return res + 1;
      }

      return res;
    }
};


int main() {
  UFUNCS(Solution::minTaps);
  return 0;
}