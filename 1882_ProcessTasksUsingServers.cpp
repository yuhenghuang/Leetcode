#include "utils3.hpp"

class Solution {
  private:
    typedef pair<int, int> pii_t;

  public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
      int n = servers.size();
      int m = tasks.size();

      // weight, index of server
      // time, index of server
      priority_queue<pii_t, vector<pii_t>, greater<pii_t>> heap_s, heap_t;

      for (int i = 0; i < n; ++i)
        heap_s.emplace(servers[i], i);

      vector<int> res(m);

      // index of task
      queue<int> q;
      for (int t = 0; t < m; ++t) {
        q.push(t);

        while (!heap_t.empty() && heap_t.top().first <= t) {
          heap_s.emplace(servers[heap_t.top().second], heap_t.top().second);
          heap_t.pop();
        }

        while (!heap_s.empty() && !q.empty()) {
          // task
          int j = q.front();
          q.pop();

          // server
          int i = heap_s.top().second;
          heap_s.pop();

          // processing
          heap_t.emplace(t + tasks[j], i);

          res[j] = i;
        }
      }

      // tasks remain after t >= m
      // thus we can skip to the time of the most recently finished task
      while (!q.empty()) {
        // time, the most recently finished task
        int t = heap_t.top().first;

        while (!heap_t.empty() && heap_t.top().first == t) {
          heap_s.emplace(servers[heap_t.top().second], heap_t.top().second);
          heap_t.pop();
        }

        while (!heap_s.empty() && !q.empty()) {
          // task
          int j = q.front();
          q.pop();

          // server
          int i = heap_s.top().second;
          heap_s.pop();

          // processing
          heap_t.emplace(t + tasks[j], i);

          res[j] = i;
        }


      }

      return res;
    }
};


int main() {
  UFUNCS(Solution::assignTasks);
  return 0;
}