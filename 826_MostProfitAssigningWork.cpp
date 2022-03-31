#include <local_leetcode.hpp>

class Solution {
  public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
      int n = difficulty.size();

      vector<pair<int, int>> tasks;
      tasks.reserve(n);

      for (int i = 0; i < n; ++i)
        tasks.emplace_back(difficulty[i], profit[i]);

      sort(tasks.begin(), tasks.end());

      sort(worker.begin(), worker.end());

      int i = 0; // task index

      int p = 0; // most profitable work currently

      int res = 0;
      for (const int& cap : worker) {
        for (; i < n && tasks[i].first <= cap; ++i)
          p = max(p, tasks[i].second);

        res += p;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::maxProfitAssignment);
  return 0;
}