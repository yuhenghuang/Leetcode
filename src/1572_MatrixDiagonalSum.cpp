#include <local_leetcode.hpp>

class Solution {
  public:
    int diagonalSum(vector<vector<int>>& mat) {
      int n = mat.size();

      int res = (n & 1) ? -mat[n/2][n/2] : 0;

      for (int i = 0; i < n; ++i) 
        res += mat[i][i] + mat[i][n - 1 - i];

      return res;
    }
};


int main() {
  EXECS(Solution::diagonalSum);
  return 0;
}