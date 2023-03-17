#include <local_leetcode.hpp>

class Solution {
  public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
      typedef pair<int, int> ii_t;

      int n = chargeTimes.size();

      // (charge time, index)
      // can be optimized to monotonic deque
      priority_queue<ii_t, vector<ii_t>, function<bool (const ii_t&, const ii_t&)>> heap(
        [] (const ii_t& p, const ii_t& q) -> bool { return p.first < q.first; }
      );

      heap.emplace(0, n);

      int64_t cost = 0;
      int j = -1;

      int res = 0;
      for (int i = 0; i < n; ++i) {
        cost += runningCosts[i];
        heap.emplace(chargeTimes[i], i);

        while (cost * (i - j) + heap.top().first > budget) {
          cost -= runningCosts[++j];

          while (heap.top().second <= j)
            heap.pop();
        }

        if (i - j > res)
          res = i - j;
      }

      return res;
    }

    int maximumRobotsMono(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
      typedef pair<int, int> ii_t;

      // monotonic deque
      // (charge time, index)
      deque<ii_t> dq;

      int64_t cost = 0;
      int j = -1;

      int res = 0;
      for (int i = 0; i < (int) runningCosts.size(); ++i) {
        cost += runningCosts[i];

        while (!dq.empty() && dq.back().first <= chargeTimes[i])
          dq.pop_back();

        dq.emplace_back(chargeTimes[i], i);

        while (!dq.empty() && cost * (i - j) + dq.front().first > budget) {
          cost -= runningCosts[++j];

          if (dq.front().second <= j)
            dq.pop_front();
        }

        if (i - j > res)
          res = i - j;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::maximumRobots);
  EXECS(Solution::maximumRobotsMono);
  return 0;
}