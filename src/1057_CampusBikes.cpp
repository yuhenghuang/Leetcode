#include <local_leetcode.hpp>

class Solution {
  private:
    typedef tuple<int, int, int> i3;

  public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
      int n = workers.size();
      int m = bikes.size();

      // dist, worker, bike
      priority_queue<i3, vector<i3>, greater<i3>> heap;

      for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
          heap.emplace(
            abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]),
            i,
            j
          );

      // used bikes
      vector<bool> seen(m);

      vector<int> res(n, -1);

      while (n > 0) {
        auto& [d, i, j] = heap.top();

        if (res[i] == -1 && !seen[j]) {
          res[i] = j;

          --n;
          seen[j] = true;
        }

        heap.pop();
      }

      return res;
    }
};


int main() {
  EXECS(Solution::assignBikes);
  return 0;
}