#include <local_leetcode.hpp>

class Solution {
  public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
      typedef pair<int, int> ii_t;
      vector<ii_t> projects; // (capital, profit)

      transform(
        capital.begin(), capital.end(),
        profits.begin(),
        back_inserter(projects),
        [] (int c, int p) -> ii_t { return {c, p}; }
      );

      // sort projects by capital
      sort(
        projects.begin(), projects.end(),
        [] (const ii_t& p, const ii_t& q) { return p.first < q.first; }
      );

      priority_queue<int> heap; // max heap, profits

      // loop for k times
      // each time update available projects and
      // pick the project with highest profit
      for (int i = 0; k > 0; --k) { // index of projects

        // update available projects
        for (; i < (int) projects.size() and projects[i].first <= w; ++i)
          heap.push(projects[i].second);

        if (heap.empty())
          break;

        // only finish the project with highest profit given current capital
        w += heap.top();
        heap.pop();
      }

      return w;
    }
};


int main() {
  EXECS(Solution::findMaximizedCapital);
  return 0;
}