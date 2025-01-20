class CherryPickupII {
  int m, n;
  int[] dir;
  int[][] grid;
  int[][][] memo;
  boolean[][][] seen;
  public int cherryPickup(int[][] grid) {
    m = grid.length;
    n = grid[0].length;
    this.grid = grid;

    dir = new int[] {-1, 0, 1};
    memo = new int[m][n][n];
    seen = new boolean[m][n][n];
    return dp(0, 0, n-1);
  }

  int dp(int i, int j, int k) {
    if (i==m || j<0 || k<0 || j>=n || k>=n) return 0;
    if (seen[i][j][k]) return memo[i][j][k];
    int res = 0;

    for (int p=0; p<3; ++p)
      for (int q=0; q<3; ++q) {
        int next_j = j + dir[p], next_k = k + dir[q];
        if (next_j>next_k) continue;
        res = Math.max(res, dp(i+1, next_j, next_k));
      }

    res += grid[i][j];
    if (j!=k)
      res += grid[i][k];

    seen[i][j][k] = true;
    memo[i][j][k] = res;
    return res;
  }
}