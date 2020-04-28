import java.util.Arrays;

class MaxSquare {
  public int maximalSquare(char[][] matrix) {
    int m = matrix.length, n = m==0?0:matrix[0].length;
    int[][] cumSum = new int[m+1][n+1];
    for (int i=1; i<=m; i++)
      for (int j=1; j<=n; j++)
        cumSum[i][j] = (matrix[i-1][j-1]-'0') + cumSum[i][j-1] + cumSum[i-1][j] - cumSum[i-1][j-1];
    
    for (int i=0; i<=m; i++) Arrays.toString(cumSum[i]);
    int res = 0;
    for (int i=0; i<m; i++)
      for (int j=0; j<n; j++)
        for (int k=1; i+k<=m && j+k<=n; k++)
          if (k*k == cumSum[i+k][j+k] -cumSum[i][j+k] - cumSum[i+k][j] + cumSum[i][j] && k*k>res) 
            res = k*k;

    return res;
  }
}