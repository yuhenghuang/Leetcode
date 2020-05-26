class UncrossedLine {
  int m, n;
  int[] A, B;
  int[][] memo;
  boolean[][] visited;
  public int maxUncrossedLines(int[] A, int[] B) {
    m = A.length;
    n = B.length;
    this.A = A;
    this.B = B;
    memo = new int[m][n];
    visited = new boolean[m][n];
    return dp(0, 0);
  }

  int dp(int a, int b) {
    if (a==m || b==n) return 0;
    if (visited[a][b]) return memo[a][b];
    int res=0;
    for (int i=a; i<m; ++i)
      for (int j=b; j<n; ++j)
        if (A[i]==B[j])
          res = Math.max(res, dp(i+1, j+1));
    
    memo[a][b] = res;
    visited[a][b] = true;
    return res;
  }
}