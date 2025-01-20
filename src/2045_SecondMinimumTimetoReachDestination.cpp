#include <unordered_set>
#include "utils3.hpp"

class Solution {
  public:
    int secondMinimum(const int n, vector<vector<int>>& edges, const int time, const int change) {
      vector<vector<int>> graph(n);

      for (auto& e : edges) {
        graph[e[0]-1].push_back(e[1]-1);
        graph[e[1]-1].push_back(e[0]-1);
      }

      vector<int> seen_prev(n), seen_next(n);

      int t = 0;
      bool reached = false;
      unordered_set<int> curr, next;

      curr.insert(0);

      while (true) {
        t += time;

        bool flag = false;
        for (int v : curr)
          for (int w : graph[v]) {
            if (seen_prev[w] >= 2) continue;
            seen_next[w] = max(seen_next[w], seen_prev[w] + 1);

            if (w == n - 1) {
              flag = true;

              if (reached)
                return t;
            }

            next.insert(w);
          }

        if ((t % (2*change)) / change)
          t = (t / (2*change) + 1) * (2*change);

        swap(seen_prev, seen_next);

        swap(curr, next);
        next.clear();

        if (flag)
          reached = true;
      }

      return -1;
    }
};


int main() {
  UFUNCS(Solution::secondMinimum);
  return 0;
}