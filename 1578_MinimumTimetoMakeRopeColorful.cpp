#include <local_leetcode.hpp>

class Solution {
  public:
    int minCost(string colors, vector<int>& neededTime) {
      int res = 0;

      int t = neededTime[0];
      int sum = t;
      int count = 1;
      for (int i = 1; i < colors.size(); ++i)
        if (colors[i] == colors[i-1]) {
          t = max(t, neededTime[i]);
          sum += neededTime[i];
          ++count;
        }
        else {
          if (count > 1)
            res += sum - t;

          sum = t = neededTime[i];
          count = 1;
        }

      if (count > 1)
        res += sum - t;

      return res;
    }
};


int main() {
  EXECS(Solution::minCost);
  return 0;
}