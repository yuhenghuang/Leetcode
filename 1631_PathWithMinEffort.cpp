#include "utils2.hpp"

class Solution {
  public:
    int minimumEffortPath(vector<vector<int>>& heights) {
      const int m = heights.size(), n = m==0 ? 0 : heights[0].size();

      bool seen[m][n];
      memset(seen, 0, m*n);

      static const int dir[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
      const int target = m*n-1;

      priority_queue<
        pair<int, int>, 
        vector<pair<int, int>>,
        greater<pair<int, int>>> heap;

      heap.emplace(0, 0);
      while (!heap.empty()) {
        auto p = heap.top(); heap.pop();
        int idx = p.second;
        if (idx==target)
          return p.first;

        int p_i = idx / n, p_j = idx % n;
        if (seen[p_i][p_j])
          continue;
        
        seen[p_i][p_j] = true;
        for (int k=0; k<4; ++k) {
          int i = p_i + dir[k][0];
          int j = p_j + dir[k][1];
          if (i<0 || i>=m || j<0 || j>=n || seen[i][j])
            continue;

          heap.emplace(
            max(p.first, abs(heights[i][j] - heights[p_i][p_j])),
            i*n+j
          );
        }
      }

      return 0;
    }
};


int main() {
  UFUNC(Solution::minimumEffortPath);
  return 0;
}