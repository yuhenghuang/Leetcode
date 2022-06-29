#include <local_leetcode.hpp>

class Solution {
  public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
      int n = capacity.size();

      vector<int> remains(n);
      for (int i = 0; i < n; ++i)
        remains[i] = capacity[i] - rocks[i];

      sort(remains.begin(), remains.end());

      int i = 0;
      for (; i < n; ++i) {
        additionalRocks -= remains[i];

        if (additionalRocks < 0)
          return i;
      }

      return n;
    }
};


int main() {
  EXECS(Solution::maximumBags);
  return 0;
}