public class NumberofClosedIsland {
  public static void main(String[] args) {
    NumberofClosedIsland obj = new NumberofClosedIsland();
    int[][] grid = new int[][] {
      {1,1,1,1,1,1,1,0},
      {1,0,0,0,0,1,1,0},
      {1,0,1,0,1,1,1,0},
      {1,0,0,0,0,1,0,1},
      {1,1,1,1,1,1,1,0}
    };
    System.out.println(obj.closedIsland(grid));
  }
  int m, n;
  int[] dir_row, dir_clm;
  boolean[][] visited;
  public int closedIsland(int[][] grid) {
    m = grid.length;
    n = m==0?0:grid[0].length;
    visited = new boolean[m][n];
    dir_row = new int[] {1,-1,0,0};
    dir_clm = new int[] {0,0,1,-1};
    int res=0;
    for (int i=0; i<m; i++)
      for (int j=0; j<n; j++)
        if (!visited[i][j] && grid[i][j]==0 && dfs(i, j, grid))
          res++;
    return res;
  }

  public boolean dfs(int i, int j, int[][] grid) {
    if (i<0|| i>=m || j<0 || j>=n) return false;
    else if (grid[i][j]==1 || visited[i][j]) return true;
    visited[i][j] = true;
    boolean res=true;
    for (int k=0; k<4; ++k) 
      if (!dfs(i+dir_row[k], j+dir_clm[k], grid))
        res=false;
    return res;
  }
}