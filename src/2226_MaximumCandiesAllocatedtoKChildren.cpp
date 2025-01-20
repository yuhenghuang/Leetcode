#include <local_leetcode.hpp>

class Solution {
  public:
    int maximumCandies(vector<int>& candies, long long k) {
      int l = 1, r = 1e7;

      while (l <= r) {
        int m = l + (r - l) / 2;

        // piles of size m
        long long p = 0;

        for (const int& candy : candies)
          p += candy / m;

        if (p >= k)
          l = m + 1;
        else
          r = m - 1;
      }

      return l - 1;
    }
};


int main() {
  EXECS(Solution::maximumCandies);
  return 0;
}