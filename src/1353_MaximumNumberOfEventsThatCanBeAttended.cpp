#include "utils3.hpp"

class Solution {
  public:
    int maxEvents(vector<vector<int>>& events) {
      sort(events.begin(), events.end());

      int res = 0;

      int t = 0;
      for (auto& e : events) {
        if (e[1] < t) continue;
        t = max(t, e[0]) + 1;
        ++res;
      }

      return res;
    }
};


int main() {
  UFUNCS(Solution::maxEvents);
  return 0;
}