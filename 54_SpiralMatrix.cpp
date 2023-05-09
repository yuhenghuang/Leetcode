#include <local_leetcode.hpp>

class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      constexpr int dirs[4][2] {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

      int m = matrix.size() - 1;
      int n = matrix[0].size();

      int i = 0;
      int j = -1;
      int d = 0;

      vector<int> res;
      while (m >= 0 && n >= 0) {
        int& l = (d & 1) ? m : n;

        for (int k = 0; k < l; ++k) {
          i += dirs[d][0];
          j += dirs[d][1];
          res.push_back(matrix[i][j]);
        }

        --l;
        d = (d + 1) % 4;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::spiralOrder);
  return 0;
}