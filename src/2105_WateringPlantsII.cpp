#include "utils3.hpp"

class Solution {
  public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
      int a = capacityA;
      int b = capacityB;
      int res = 0;

      int i = 0;
      int j = (int)plants.size() - 1;
      while (i < j) {
        if (a < plants[i]) {
          a = capacityA;
          ++res;
        }

        a -= plants[i];

        if (b < plants[j]) {
          b = capacityB;
          ++res;
        }

        b -= plants[j];

        ++i;
        --j;
      }

      // last plant where Alice and Bob reunite
      if (i == j && max(a, b) < plants[i])
        ++res;

      return res;
    }
};


int main() {
  UFUNCS(Solution::minimumRefill);
  return 0;
}