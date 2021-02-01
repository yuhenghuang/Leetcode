#include "utils2.hpp"

class Solution {
  public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
      size_t n = position.size();

      vector<size_t> indices(n);
      for (size_t i =0; i<n; ++i)
        indices[i] = i;

      sort(
        indices.begin(), indices.end(),
        [&position](size_t i, size_t j) -> bool {
          return position[i] > position[j];
        }
      );

      int res = 0;
      double time = 0;
      for (size_t i : indices) {
        double temp = double(target - position[i]) / double(speed[i]);
        if (temp > time) {
          ++res;
          time = temp;
        }
      }

      return res;
    }
};


int main() {
  UFUNC(Solution::carFleet);
  return 0;
}