#include <local_leetcode.hpp>

class Solution {
  public:
    int shipWithinDays(vector<int>& weights, int days) {
      int l = 0; // left bound, initialized with max of weights
      int r = 0; // right bound, initialized with sum of weights
      for (int w : weights) {
        if (w > l)
          l = w;

        r += w;
      }

      while (l < r) {
        int m = l + (r - l) / 2;

        int load = 0; // load of current ship
        int d = 1; // # of days or ships
        for (int w : weights) {
          load += w;
          // a new ship needed
          if (load > m) {
            ++d;
            load = w;
          }
        }

        if (d > days)
          l = m + 1;
        else
          r = m;
      }

      return l;
    }
};


int main() {
  EXECS(Solution::shipWithinDays);
  return 0;
}
