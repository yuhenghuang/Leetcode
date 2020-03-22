import java.awt.Point;
import java.util.Stack;

public class MaxAreaIsland {


  public int maxAreaOfIsland_iter(int[][] grid) {
    int[] dr= new int[]{1, -1, 0, 0};
    int[] dc= new int[]{0, 0, 1, -1};

    m = grid.length;
    n = m>0?grid[0].length:0;
    int res = 0;

    boolean[][] visited = new boolean[m][n];
    for (int i=0; i<m; ++i)
      for (int j=0; j<n; ++j)
        if (grid[i][j]==1 && !visited[i][j]) {
          visited[i][j]=true;
          Stack<Point> stack = new Stack<>();
          stack.push(new Point(i, j));
          int temp=0;
          while (!stack.isEmpty()) {
            Point p = stack.pop();
            int x = p.x; int y = p.y;
            temp++;
            for (int k=0; k<4; ++k) {
              int nx = x+dr[k];
              int ny = y+dc[k];
              if (nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1 && !visited[nx][ny]) {
                stack.push(new Point(nx, ny));
                visited[nx][ny]=true;
              }
            }
          }
          res=Math.max(res, temp);
        }
    return res;
  }





  int m, n;
  int [][] grid;
  boolean[][] visited;
  public int maxAreaOfIsland_recur(int[][] grid) {
    m = grid.length;
    n = m>0?grid[0].length:0;
    int res = 0;
    this.grid = grid;
    visited = new boolean[m][n];

    for (int i=0; i<m; ++i)
      for (int j=0; j<n; ++j)
        if (grid[i][j]==1 && !visited[i][j])
          res = Math.max(res, dfs(i, j));
    return res;
  }

  public int dfs(int i, int j) {
    if (i<0 || i>m-1 || j<0 || j>n-1 || grid[i][j]==0 || visited[i][j]) return 0;
    visited[i][j]=true;
    return 1+dfs(i+1, j) + dfs(i, j+1) + dfs(i-1, j) + dfs(i, j-1);
  }
}