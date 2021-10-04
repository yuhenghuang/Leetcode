#include "utils3.hpp"

class Solution {
  public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
      for (auto& op : ops) {
        m = min(m, op[0]);
        n = min(n, op[1]);
      }

      return m * n;
    }
};


int main() {
  UFUNCS(Solution::maxCount);
  return 0;
}