public class NumberofIslands {
  int nrow, ncol;
  boolean[][] seen;
  public int numIslands(char[][] grid) {
    nrow=grid.length;
    ncol= nrow==0?0:grid[0].length;
    int res=0;
    seen = new boolean[nrow][ncol];


    for (int i=0; i<nrow; ++i) {
      for (int j=0; j<ncol; ++j) {
        if (grid[i][j]=='1' && !seen[i][j]) {
          res+=1;
          dfs(grid, i, j);
        } 
      }
    }
    return res;
  }

  public void dfs (char[][] grid, int i, int j) {
    if (i < 0 || i >= nrow || j < 0 || j >= ncol || grid[i][j] == '0') return;
    if (seen[i][j]) return;
    seen[i][j]=true;

    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
  }
}