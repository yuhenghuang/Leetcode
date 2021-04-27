#include "utils2.hpp"

class Solution {
  public:
    int leastBricks(vector<vector<int>>& wall) {
      unordered_map<int, int> m;
      for (auto& row : wall) {
        int width = 0;
        for (int i = 0; i < row.size() - 1; ++i) {
          width += row[i];
          ++m[width];
        }
      }
      
      int res = 0;
      for (auto& p : m)
        res = max(res, p.second);
      
      return wall.size() - res;
    }
};


int main() {
  UFUNC(Solution::leastBricks);
  return 0;
}