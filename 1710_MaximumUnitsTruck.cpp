#include "utils2.hpp"

class Solution {
  public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
      sort(
        boxTypes.begin(), boxTypes.end(),
        [](const vector<int>& x, const vector<int>& y) -> bool {
          return x[1] > y[1];
        }
      );

      auto iter = boxTypes.cbegin();

      int res = 0;
      while (truckSize > 0 && iter != boxTypes.cend()) {
        res += min(truckSize, iter->front()) * iter->back();

        truckSize -= (iter++)->front();
      }

      return res;
    }
};


int main() {
  UFUNC(Solution::maximumUnits);
  return 0;
}