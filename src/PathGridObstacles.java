import java.util.ArrayDeque;
import java.util.Queue;

public class PathGridObstacles {
  int m, n;
  boolean[][][] seen;
  public int shortestPath(int[][] grid, int k) {
    m = grid.length;
    n = m==0?0:grid[0].length;
    if (n==0 || grid[0][0]>k) return -1;
    else if (m==1 && n==1) return 0;

    seen = new boolean[m][n][k];
    Queue<int[]> queue = new ArrayDeque<>();
    int res = 1;
    queue.offer(new int[]{0, 0, grid[0][0]});
    seen[0][0][grid[0][0]]=true;
    int[] dir_row = new int[] {1,-1,0,0};
    int[] dir_clm = new int[] {0,0,1,-1};

    while(!queue.isEmpty()) {
      int s = queue.size();
      while(s-->0) {
        int[] bundle = queue.poll();
        for (int d=0; d<4; ++d) {
          int i = bundle[0] + dir_row[d];
          int j = bundle[1] + dir_clm[d];
          if (i<0 || j<0 || i>=m || j>=n || bundle[2]+grid[i][j]>k)
            continue;
          int next_k = bundle[2]+grid[i][j];
          if (!seen[i][j][next_k]) {
            queue.offer(new int[] {i, j, next_k});
            seen[i][j][next_k]=true;
          }
          if (i==m-1 && n==n-1) return res;
        }
      }
      res++;
    }

    for (int p=0; p<=k; ++p)
      if (seen[m-1][n-1][p])
        return res;
    return -1;
  }
}