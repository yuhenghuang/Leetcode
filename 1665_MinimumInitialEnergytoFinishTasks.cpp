#include "utils3.hpp"

class Solution {
  public:
    int minimumEffort(vector<vector<int>>& tasks) {
      // do tasks with least minimum - actual last
      sort(
        tasks.begin(), tasks.end(),
        [](auto& x, auto& y) {
          return x[1] - x[0] < y[1] - y[0];
        }
      );

      int res = 0;
      for (auto& t : tasks)
        res = max(res + t[0], t[1]);

      return res;
    }
};


int main() {
  UFUNCS(Solution::minimumEffort);
  return 0;
}