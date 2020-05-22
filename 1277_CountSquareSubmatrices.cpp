#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

static int i = []() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();

class Solution {
  public:
    int countSquares(vector<vector<int>>& matrix) {
      int m = matrix.size(), n = m==0 ? 0 : matrix[0].size();
      int res = 0;
      for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j) {
          if (i>0 && j>0 && matrix[i][j]==1) 
            matrix[i][j] += min(min(matrix[i-1][j], matrix[i][j-1]), matrix[i-1][j-1]);
          res += matrix[i][j];
        }
      return res;
    }
};


int main() {
  vector<vector<int>> vec(3, vector<int>(4, 1));
  vec[0][0] = 0;
  vec[2][0] = 0;
  Solution sol;
  cout << sol.countSquares(vec) << endl;
  return 0;
}