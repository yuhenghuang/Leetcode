#include <local_leetcode.hpp>

class Solution {
  public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
      priority_queue<int> heap;
      stations.push_back({target, 0});

      int res = 0;
      for (const auto& p : stations) {
        while (startFuel < p[0] && !heap.empty()) {
          startFuel += heap.top();
          heap.pop();

          ++res;
        }

        if (startFuel < p[0])
          return -1;

        heap.push(p[1]);
      }

      return res;
    }
};


int main() {
  EXECS(Solution::minRefuelStops);
  return 0;
}
