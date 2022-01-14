#include <local_leetcode.hpp>

class Solution {
  private:
    int find_depth(const NestedInteger& ni, int d) {
      if (ni.isInteger())
        return d;

      int depth = d++;
      for (const NestedInteger& descend : ni.getList())
        depth = max(depth, find_depth(descend, d));

      return depth;
    }

    int weighted_sum(const NestedInteger& ni, int w) {
      if (ni.isInteger())
        return ni.getInteger() * w;

      int sum = 0;
      for (const NestedInteger& descend : ni.getList())
        sum += weighted_sum(descend, w - 1);

      return sum;
    }

  public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
      int depth = 0;
      for (const NestedInteger& ni : nestedList)
        depth = max(depth, find_depth(ni, 1));

      int res = 0;
      for (const NestedInteger& ni : nestedList)
        res += weighted_sum(ni, depth);

      return res;
    }
};


int main() {
  EXECS(Solution::depthSumInverse);
  return 0;
}