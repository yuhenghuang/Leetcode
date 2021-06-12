#include "utils2.hpp"

class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
      int n = cost.size();

      if (n < 2)
        return 0;

      for (int i = 2; i < n; ++i)
        cost[i] += min(cost[i-1], cost[i-2]);

      return min(cost[n-1], cost[n-2]);
    }
};


int main() {
  UFUNC(Solution::minCostClimbingStairs);
  return 0;
}