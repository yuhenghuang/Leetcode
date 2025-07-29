#include <local_leetcode.hpp>

class Solution {
  public:
    int maxEventsWrong(vector<vector<int>>& events) {
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

    int maxEvents(vector<vector<int>>& events) {
      typedef pair<int, int> i2_t;

      vector<i2_t> vec(events.size());
      transform(
        events.begin(), events.end(),
        vec.begin(),
        [] (const vector<int>& e) { return i2_t(e[0], e[1]); }
      );

      sort(
        vec.begin(), vec.end(),
        [] (const i2_t& p, const i2_t& q) { return p.first < q.first or (p.first == q.first and p.second < q.second); }
      );

      int res = 0;

      int t = 0;
      for (auto& e : vec) {
        if (e.second < t) continue;
        t = max(t, e.first) + 1;
        ++res;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::maxEventsWrong);
  EXECS(Solution::maxEvents);
  return 0;
}
