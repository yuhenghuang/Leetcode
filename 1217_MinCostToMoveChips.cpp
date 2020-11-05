#include "utils.hpp"

class Solution {
  public:
    int minCostToMoveChips(vector<int>& position) {
      int even = 0, odd = 0;
      for (const int& p : position) {
        if (p%2==0)
          ++even;
        else
          ++odd;
      }

      return min(even, odd);
    }
};


int main() {
  UFUNC(Solution::minCostToMoveChips);
  return 0;
}