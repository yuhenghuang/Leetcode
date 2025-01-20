#include <local_leetcode.hpp>

class Solution {
  public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
      const int n = points.size();

      vector<int> xs;
      for (auto& p : points)
        xs.push_back(p[0]);

      sort(xs.begin(), xs.end());

      int res = 0;
      for (int i = 1; i < n; ++i)
        res = max(res, xs[i] - xs[i-1]);

      return res;
    }
};


int main() {
  EXECS(Solution::maxWidthOfVerticalArea);
  return 0;
}