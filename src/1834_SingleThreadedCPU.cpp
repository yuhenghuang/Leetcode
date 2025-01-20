#include <local_leetcode.hpp>

class Solution {
  public:
    vector<int> getOrder(vector<vector<int>>& _tasks) {
      typedef pair<int, int> ii_t;
      typedef tuple<int, int, int> iii_t;

      int n = _tasks.size();
      // enqueueTime, processingTime, index
      vector<iii_t> tasks; tasks.reserve(n);

      for (int i = 0; i < n; ++i) {
        const auto& task = _tasks[i];
        tasks.emplace_back(task[0], task[1], i);
      }

      // sort tasks by enqueueTime ONLY, no need to waste time on sorting other dimensions
      sort(tasks.begin(), tasks.end(), [](const iii_t& i, const iii_t& j) { return get<0>(i) < get<0>(j); });

      // min heap of (processingTime, index)
      priority_queue<ii_t, vector<ii_t>, greater<ii_t>> heap;
      // index over sorted tasks
      int index = 0;
      // global time
      int64_t time = 0;

      vector<int> res; res.reserve(n);
      while (!heap.empty() || index < n) {

        if (heap.empty())
          time = max(time, (int64_t) get<0>(tasks[index]));

        for (; index < n && get<0>(tasks[index]) <= time; ++index)
          heap.emplace(get<1>(tasks[index]), get<2>(tasks[index]));
        
        auto [t, i] = heap.top();
        heap.pop();

        res.push_back(i);
        time += t;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::getOrder);
  return 0;
}