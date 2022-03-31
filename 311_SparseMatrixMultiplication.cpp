#include <local_leetcode.hpp>

class Solution {
  public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
      int m = mat1.size();
      int l = mat2.size();
      int n = mat2[0].size();

      vector<vector<int>> res(m, vector<int>(n));

      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
          int sum = 0;
          
          for (int k = 0; k < l; ++k)
            sum += mat1[i][k] * mat2[k][j];

          res[i][j] = sum;
        }

      return res;
    }
};


int main() {
  EXECS(Solution::multiply);
  return 0;
}