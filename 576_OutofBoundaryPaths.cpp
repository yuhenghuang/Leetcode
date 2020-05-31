#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

class Solution {
  private:
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
  public:
    int findPaths(int m, int n, int N, int i, int j) {
      vector<vector<long>> mat(m, vector<long>(n, 0));
      mat[i][j] = 1;
      long mod = 1e9 + 7;
      long res = 0;

      while (N--) {
        copy(mat[0].begin(), mat[0].end(), ostream_iterator<long>(cout, ", "));
        vector<vector<long>> mat_next(m, vector<long>(n, 0));
        for (int row=0; row<m; ++row)
          for (int clm=0; clm<n; ++clm)
            for (int k=0; k<4; ++k) {
              int r = row + dir[k][0], c = clm + dir[k][1];
              if (r<0 || r>=m || c<0 || c>=n) {
                res += mat[row][clm];
                res %= mod;
              }
              else {
                mat_next[r][c] += mat[row][clm];
                mat_next[r][c] %= mod;
              }
            }
        mat = mat_next;
      }
      return res;
    }
};

int main() {
  Solution sol;
  cout << sol.findPaths(1, 3, 3, 0, 1) << endl;
  return 0;
}