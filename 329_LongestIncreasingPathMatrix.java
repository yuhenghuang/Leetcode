class LongestIncreasingPathMatrix {
  int m, n;
  int[][] memo, matrix;
  boolean[][] visiting;
  public int longestIncreasingPath(int[][] matrix) {
    this.matrix = matrix;
    m=matrix.length;
    n=m==0?0:matrix[0].length;
    memo = new int[m][n];
    visiting = new boolean[m][n];

    int res=0;
    for (int i=0; i<m; ++i)
      for (int j=0; j<n; ++j)
        res = Math.max(res, dfs(Integer.MIN_VALUE, i, j));
    return res;
  }

  public int dfs(int num, int i, int j) {
    if (i<0 || i>=m || j<0 || j>=n || visiting[i][j]|| matrix[i][j]<=num) return 0;
    if (memo[i][j]>0) return memo[i][j];

    visiting[i][j] = true;
    memo[i][j] = 1 + Math.max(Math.max(dfs(matrix[i][j], i+1, j), dfs(matrix[i][j], i-1, j)),
                              Math.max(dfs(matrix[i][j], i, j+1), dfs(matrix[i][j], i, j-1)));
    visiting[i][j] = false;
    return memo[i][j];
  }
}