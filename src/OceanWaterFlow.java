import java.util.List;
import java.util.ArrayList;

public class OceanWaterFlow {

  int m, n;
  int[][] matrix;
  boolean[][] av, pv;
  public List<List<Integer>> pacificAtlantic(int[][] matrix) {
    m=matrix.length;
    n=m>0?matrix[0].length:0;
    List<List<Integer>> res = new ArrayList<>();
    if (m==0 || n==0) return res;

    this.matrix=matrix;
    av = new boolean[m][n];
    pv = new boolean[m][n];
    
    for (int i=0; i<m; ++i) {
      dfs(i, 0, 0 , pv);
      dfs(i, n-1, 0, av);
    }
    for (int j=0; j<n; ++j) {
      dfs(0, j, 0, pv);
      dfs(m-1, j, 0, av);
    }

    for (int i=0; i<m; ++i) 
      for (int j=0; j<n; ++j)
        if (av[i][j] && pv[i][j])
          res.add(new ArrayList<>(List.of(i, j)));

    return res;
  }

  public void dfs(int i, int j, int height, boolean[][] visited) {
    if (i<0 || i>m-1 || j<0 || j>n-1 || matrix[i][j]<height) return;
    visited[i][j]=true;

    dfs(i+1, j, matrix[i][j], visited);
    dfs(i-1, j, matrix[i][j], visited);
    dfs(i, j+1, matrix[i][j], visited);
    dfs(i, j-1, matrix[i][j], visited);
  }
}