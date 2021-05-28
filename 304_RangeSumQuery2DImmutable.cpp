#include <vector>

using namespace std;

class NumMatrix {
  private:
    vector<vector<int>> mat;

  public:
    NumMatrix(vector<vector<int>>& matrix) {
      int m = matrix.size(), n = matrix[0].size();

      mat.resize(m+1);

      for (int i = 0; i < m; ++i) {
        mat[i].resize(n+1);

        for (int j = 0; j < n; ++j)
          mat[i+1][j+1] = mat[i][j+1] + mat[i][j+1] - mat[i][j] + matrix[i][j];
      }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
      return mat[row2+1][col2+1] - mat[row1][col2+1] - mat[row2+1][col1] + mat[row1][col1];
    }
};