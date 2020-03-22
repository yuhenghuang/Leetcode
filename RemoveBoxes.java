public class RemoveBoxes {
  int[] boxes;
  int[][][] memo;
  public int removeBoxes(int[] boxes) {
    this.boxes = boxes;
    int N = boxes.length;
    memo = new int[N][N][N];
    return dfs(0, boxes.length-1, 0);
  }

  public int dfs(int i, int j, int k) {
    if (i>j) return 0;
    if (memo[i][j][k]!=0) return memo[i][j][k];

    int res = (k+1)*(k+1) + dfs(i+1, j, 0);
    for (int m=i+1; m<=j; ++m) {
      if (boxes[m]==boxes[i])
        res=Math.max(res, dfs(i+1, m-1, 0) + dfs(m, j, k+1));
    }
    memo[i][j][k]=res;
    return res;
  }
}