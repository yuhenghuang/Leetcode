#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
      int m = mat.size(), n = mat[0].size();
      vector<vector<int>> container(m+n-1);
      vector<vector<int>> res(m, vector<int>(n));

      for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
          container[j-i+m-1].push_back(mat[i][j]);

      for (auto& diag : container)
        sort(diag.begin(), diag.end());

      for (int i=m-1; i>=0; --i)
        for (int j=0; j<n; ++j) {
          res[i][j] = container[j-i+m-1].back();
          container[j-i+m-1].pop_back();
        }
      return res;
    }
};

int main() {
  vector<vector<int>> mat = {{3,3,1,1}, {2,2,1,2}, {1,1,1,2}};
  Solution sol;
  sol.diagonalSort(mat);
  return 0 ;
}