#include "utils.hpp"

class Solution {
  public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
      int m = matrix.size(), n = m==0 ? 0 : matrix[0].size();

      vector<int> res;
      res.reserve(m*n);

      bool flag = true;
      for (int k=0; k<m+n-1; ++k) {
        if (flag) {
          int i = min(k, m-1), j = k-i;
          int cnt = min(i+1, n-j);
          while (cnt--) 
            res.push_back(matrix[i--][j++]);
        }
        else {
          int j = min(k, n-1), i = k-j;
          int cnt = min(m-i, j+1);
          while (cnt--) 
            res.push_back(matrix[i++][j--]);
        }
        
        flag = !flag;
      }

      return res;
    }
};


int main() {
  UFUNC(Solution::findDiagonalOrder);
  return 0;
}