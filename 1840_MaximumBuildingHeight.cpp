#include "utils3.hpp"

class Solution {
  private:
    int computeHeight(int p, int q, int d) {
      if (p > q)
        return computeHeight(q, p, d);

      // p <= q
      return min(p + d, max(p + d - q, 0) / 2 + q);
    }

  public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
      // partially wrong answer
      
      if (restrictions.empty())
        return n - 1;

      sort(restrictions.begin(), restrictions.end());

      // ~~need to define heights more carefully, sad...~~
      // updated height limits when looping from left to right
      vector<int> heights(restrictions.size());
      
      int i = 1;
      int p = 0;

      // (i, p) -> (j, q)
      for (int k = 0; k < restrictions.size(); ++k) {
        int j = restrictions[k][0];
        int q = restrictions[k][1];

        p = heights[k] = min(q, p + j - i);
        i = j;
      }

      // height at label n (btw last restriction and n)
      int res = p + n - i;

      // (j, q) <- (i, p)
      for (int k = restrictions.size() - 2; k >= 0; --k) {
        int j = restrictions[k][0];
        int q = heights[k];

        res = max(res, computeHeight(p, q, i - j));

        p = min(q, p + i - j);
        i = j;
      }

      // height btw 1 and first restriction
      return max(res, computeHeight(0, p, i - 1));
    }
};


int main() {
  UFUNCS(Solution::maxBuilding);
  return 0;
}