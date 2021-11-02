#include "utils3.hpp"

class Solution {
  public:
    int getMaximumConsecutive(vector<int>& coins) {
      sort(coins.begin(), coins.end());

      int res = 0;
      for (int c : coins) {
        if (c > res + 1)
          break;

        res += c;
      }

      return res + 1;
    }
};


int main() {
  UFUNCS(Solution::getMaximumConsecutive);
  return 0;
}