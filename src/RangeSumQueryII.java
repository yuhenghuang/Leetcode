class NumMatrix {
  int[][] cumSum;
  public NumMatrix(int[][] matrix) {
    int m = matrix.length, n = m==0?0:matrix[0].length;
    cumSum = new int[m+1][n+1];
    for (int i=0; i<m; ++i)
      for (int j=0; j<n; ++j)
        cumSum[i+1][j+1] = matrix[i][j] + cumSum[i][j+1] + cumSum[i+1][j] - cumSum[i][j];
  }
  
  public int sumRegion(int row1, int col1, int row2, int col2) {
    return cumSum[row2+1][col2+1] - cumSum[row2+1][col1] - cumSum[row1][col2+1] + cumSum[row1][col1];
  }
}