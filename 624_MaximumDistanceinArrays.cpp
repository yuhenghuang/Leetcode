#include "utils3.hpp"

class Solution {
  public:
    int maxDistance(vector<vector<int>>& arrays) {
      int curr_min = arrays[0].front();
      int curr_max = arrays[0].back();

      int res = 0;

      for (size_t i = 1; i < arrays.size(); ++i) {
        res = max(res,
          max(
            abs(arrays[i].back() - curr_min),
            abs(arrays[i].front() - curr_max)
          )
        );

        curr_min = min(curr_min, arrays[i].front());
        curr_max = max(curr_max, arrays[i].back());
      }

      return res;
    }
};


int main() {
  UFUNCS(Solution::maxDistance);
  return 0;
}