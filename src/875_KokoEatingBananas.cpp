#include <local_leetcode.hpp>

class Solution {
  public:
    int minEatingSpeed(vector<int>& piles, int h) {
      int l = 1, r = INT_MAX;
      while (l <= r) {
        int m = l + (r - l) / 2;

        int hours = 0;
        for (const int& p : piles)
          hours += p / m + (p % m == 0 ? 0 : 1);

        if (hours > h)
          l = m + 1;
        else
          r = m - 1;
      }

      return l;
    }
};


int main() {
  EXECS(Solution::minEatingSpeed);
  return 0;
}