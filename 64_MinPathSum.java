class MinPathSum {
  public int minPathSum(int[][] grid) {
    int m=grid.length, n= m==0?0:grid[0].length;
    if (m==0 || n==0) return 0;
    //int[][] dp = new int[m][n];
    //dp[0][0] = grid[0][0];
    for (int i=1; i<m; i++) 
      grid[i][0] = grid[i-1][0] + grid[i][0];
    for (int j=1; j<n; j++)
      grid[0][j] = grid[0][j-1] + grid[0][j];

    for (int i=1; i<m; i++)
      for (int j=1; j<n; j++)
        grid[i][j] = Math.min(grid[i-1][j], grid[i][j-1]) + grid[i][j];
    return grid[m-1][n-1];
  }

  int m, n;
  int[][] memo, grid;
  public int minPathSumRec(int[][] grid) {
    m=grid.length;
    n= m==0?0:grid[0].length;
    if (m==0 || n==0) return 0;

    this.grid = grid;
    memo = new int[m][n];
    return dp(m-1, n-1);
  }

  int dp(int i, int j) {
    if (i<0 || i>=m || j<0 || j>=n) return Integer.MAX_VALUE;
    if (memo[i][j]>0) return memo[i][j];

    memo[i][j] = grid[i][j] + Math.min(dp(i-1, j) ,dp(i, j-1));
    return memo[i][j];
  }
}