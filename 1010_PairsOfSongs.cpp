#include "utils.hpp"

class Solution {
  public:
    int numPairsDivisibleBy60(vector<int>& time) {
      int count[60] = {0};
      for (int du : time)
        ++count[du % 60];

      int res = count[0] ? count[0] * (count[0]-1) / 2 : 0;
      res += count[30] ? count[30] * (count[30]-1) / 2 : 0;

      for (int i=1; i<30; ++i)
        res += count[i] * count[60-i];

      return res;
    }
};


int main() {
  UFUNC(Solution::numPairsDivisibleBy60);
  return 0;
}