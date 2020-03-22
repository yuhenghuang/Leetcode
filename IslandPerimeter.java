public class IslandPerimeter {
  public static void main(String[] args) {
    IslandPerimeter obj = new IslandPerimeter();
    int[][] grid = new int[][] {
      {0,1,0,0},
      {1,1,1,0},
      {0,1,0,0},
      {1,1,0,0}
    };
    System.out.println(obj.islandPerimeter(grid));
  }
  int m, n;
  int[] dir_row, dir_clm;
  boolean[][] visited;
  public int islandPerimeter(int[][] grid) {
    m = grid.length;
    n = m==0?0:grid[0].length;
    dir_row = new int[] {1, -1, 0, 0};
    dir_clm = new int[] {0, 0, 1, -1};
    visited = new boolean[m][n];
    for (int i=0; i<m; ++i)
      for (int j=0; j<n; ++j)
        if (grid[i][j]==1)
          return dfs(i, j, grid);
    return 0;
  }

  public int dfs(int i, int j, int[][] grid) {
    if (i<0 || i>=m || j<0 || j>=n || grid[i][j]==0) return 1;
    else if (visited[i][j]) return 0;
    visited[i][j]=true;
    int res=0;
    for (int k=0; k<4; ++k)
      res+=dfs(i+dir_row[k], j+dir_clm[k], grid);
    return res;
  }
}