#define _LL_NONTRIVIAL_SOLUTION_CTOR
#include <local_leetcode.hpp>

class Solution {
  private:
    typedef tuple<int, int, int> i3;

    vector<int> parent;

    int find(int p) {
      if (parent[p] == -1)
        return p;

      return parent[p] = find(parent[p]);
    }

    bool join(int p, int q) {
      p = find(p);
      q = find(q);

      if (p != q) {
        parent[q] = p;

        return true;
      }

      return false;
    }

  public:
    int minCostConnectPoints(vector<vector<int>>& points) {
      int n = points.size();

      parent.assign(n, -1);

      priority_queue<i3, vector<i3>, greater<i3>> heap;

      for (int i = 1; i < n; ++i)
        for (int j = 0; j < i; ++j) {
          heap.emplace(
            abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), 
            j, 
            i
          );
        }

      int res = 0;

      // n - 1 edges needed
      while (n > 1) {
        auto& [d, u, v] = heap.top();

        if (join(u, v)) {
          res += d;
          --n;
        }

        heap.pop();
      }

      return res;
    }
};


int main() {
  EXECS(Solution::minCostConnectPoints);
  return 0;
}