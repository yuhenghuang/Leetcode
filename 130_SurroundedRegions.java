class SurroundedRegions {
  int m, n;
  int[][] dir;
  char[][] board;
  boolean[][] seen;
  public void solve(char[][] board) {
    m = board.length;
    n = m==0 ? 0 : board[0].length;
    seen = new boolean[m][n];

    this.board = board;
    dir = new int[][]{{1,0}, {-1,0}, {0,1}, {0,-1}};

    for (int i=0; i<m; ++i) {
      dfs(i, 0);
      dfs(i, n-1);
    }

    for (int j=1; j<n-1; ++j) {
      dfs(0, j);
      dfs(m-1, j);
    }

    for (int i=0; i<m; ++i)
      for (int j=0; j<n; ++j)
        if (!seen[i][j] && board[i][j]=='O')
          board[i][j] = 'X';
  }

  void dfs(int i, int j) {
    if (i<0 || i>=m || j<0 || j>=n || board[i][j]=='X' || seen[i][j]) return;
    seen[i][j] = true;
    for (int k=0; k<4; ++k)
      dfs(i+dir[k][0], j+dir[k][1]);
  }
}