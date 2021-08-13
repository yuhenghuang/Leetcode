#include "utils3.hpp"

class Solution {
  public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
      int m = A.size(), n = m==0 ? 0 : A[0].size();

      vector<vector<int>> res(m, vector<int>(n));

      for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
          res[i][j] = 1 ^ A[i][n-j-1];
      
      return res;
    }
};


int main() {
  UFUNCS(Solution::flipAndInvertImage);
  return 0;
}