#include <local_leetcode.hpp>

class Solution {
  public:
    int maxCoins(vector<int>& piles) {
      const int n = (piles.size() / 3) * 2;

      // use bucket sort (count sort?) to reduce complexity
      sort(piles.begin(), piles.end(), greater<>());

      int res = 0;

      for (int i = 1; i < n; i += 2)
        res += piles[i];

      return res;
    }
};


int main() {
  EXECS(Solution::maxCoins);
  return 0;
}