#include <local_leetcode.hpp>

class Solution {
  public:
    long long minimumTime(vector<int>& time, int totalTrips) {
      typedef long long long_t;

      long_t l = 1, r = 1e14;
      while (l < r) {
        long_t m = l + (r - l) / 2;

        long_t currTrips = 0;
        for (const int& t : time)
          currTrips += m / t;

        if (currTrips < totalTrips)
          l = m + 1;
        else
          r = m;
      }

      return l;
    }
};


int main() {
  EXECS(Solution::minimumTime);
  return 0;
}