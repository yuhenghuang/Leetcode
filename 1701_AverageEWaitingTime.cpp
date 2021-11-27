#include "utils3.hpp"

class Solution {
  public:
    double averageWaitingTime(vector<vector<int>>& customers) {
      int t = 0;
      long res = 0;

      for (auto& c : customers) {
        if (c[0] > t)
          t = c[0];

        t += c[1];
        res += t - c[0];
      }

      return res / double(customers.size());
    }
};


int main() {
  UFUNCS(Solution::averageWaitingTime);
  return 0;
}