import java.util.Arrays;

public class CheeryPickup {
  public static void main(String[] args) {
    CheeryPickup obj = new CheeryPickup();
    int [][] grid = new int[][] {{0,1,-1},{1,0,-1},{1,1,1}};
    int res = obj.cherryPickup(grid);
    System.out.println(res);
  }
  int N;
  int [][] grid;
  int [][][] memo;
  public int cherryPickup(int[][] grid) {
    N = grid.length;
    this.grid= grid;
    memo = new int[N][N][N];
    for (int[][] layer: memo)
      for (int[] row : layer)
        Arrays.fill(row, Integer.MIN_VALUE);
    
    return Math.max(0, dp(0, 0, 0));
  }

  public int dp(int r1, int c1, int r2) {
    int c2 = r1 + c1 - r2;
    if (c1==N || c2==N || r1==N || r2==N) return Integer.MIN_VALUE;
    else if (grid[r1][c1]==-1 || grid[r2][c2]==-1) return Integer.MIN_VALUE;
    else if (r1==N-1 && c1==N-1) return grid[r1][c1];
    else if (memo[r1][c1][r2]>=0) return memo[r1][c1][r2];
    else {
      int ans = grid[r1][c1];
      if (r1!=r2) ans+=grid[r2][c2];
      ans += Math.max(Math.max(dp(r1+1, c1, r2+1), dp(r1+1, c1, r2)), 
                      Math.max(dp(r1, c1+1, r2+1), dp(r1, c1+1, r2)));
      memo[r1][c1][r2]=ans;
      return ans;
    }
  }
}