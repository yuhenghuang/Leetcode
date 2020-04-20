import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;

class Matrix01 {
  public static void main(String[] args) {
    int[][] matrix = LeetcodeUtil.arrayInt2dParser("[[0,0,0], [0,1,0],[1,1,1]]");
    Matrix01 obj = new Matrix01();
    obj.updateMatrix(matrix);
    for (int[] row : matrix)
      System.out.println(Arrays.toString(row));
  }
  public int[][] updateMatrix(int[][] matrix) {
    int m = matrix.length;
    int n = m==0?0:matrix[0].length;
    boolean[][] seen = new boolean[m][n];
    Queue<int[]> queue = new ArrayDeque<>();
    for (int i=0; i<m; ++i)
      for (int j=0; j<n; ++j)
        if(matrix[i][j]==0) {
          queue.offer(new int[] {i, j});
          seen[i][j] = true;
        }
    
    int dist = 1;
    int[] dim_row = new int[] {1, -1, 0, 0}, dim_clm = new int[] {0, 0, 1, -1};
    while (!queue.isEmpty()) {
      int N = queue.size();
      while (N-->0) {
        int[] coord = queue.poll();
        for (int k=0; k<4; ++k) {
          int i = coord[0]+dim_row[k], j = coord[1]+dim_clm[k];
          if (i<0 || i>=m || j<0 || j>=n || seen[i][j]) continue;
          queue.offer(new int[] {i, j});
          seen[i][j]=true;
          matrix[i][j] = dist;
        } 
      }
      dist++;
    }
    return matrix;
  }
}