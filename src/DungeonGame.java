public class DungeonGame {
  public static void main(String[] args) {
    DungeonGame obj = new DungeonGame();
    int[][] maze = new int[][] {{-3, 5}};
    obj.calculateMinimumHP(maze);
  }

  int[][] dp;
  boolean[][] seen;
  public int calculateMinimumHP(int[][] dungeon) {
    int m = dungeon.length;
    int n = m>0?dungeon[0].length:0;
    if (m==0||n==0) return 0;
    dp = new int[m][n];
    seen = new boolean[m][n];
    dp[m-1][n-1] = Math.max(-dungeon[m-1][n-1], 0);
    seen[m-1][n-1] = true;

    dfs(0, 0, m, n, dungeon);

    for (int i=0;i<m;++i) {
      for (int j=0;j<n;++j) {
        System.out.print(dp[i][j]+"\t");
      }
      System.out.println("");
    }
    return dp[0][0]+1;
  }

  public int dfs(int i, int j, int m, int n, int[][] dungeon) {
    if (i>m-1 || j>n-1) return Integer.MAX_VALUE;
    if (seen[i][j]) return dp[i][j];
    dp[i][j]=Math.max(Math.min(dfs(i+1,j, m, n, dungeon), dfs(i, j+1, m, n, dungeon))-dungeon[i][j], 0);
    seen[i][j]=true;
    return dp[i][j];
  }


  public int calculateMinimumHP_UP(int[][] dungeon) {
    int m = dungeon.length;
    int n = m>0?dungeon[0].length:0;
    if (m==0||n==0) return 0;
    dp = new int[m][n];

    dp[m-1][n-1]=Math.max(-dungeon[m-1][n-1], 0);
    for (int i=m-2; i>=0; --i) dp[i][n-1]=Math.max(dp[i+1][n-1]-dungeon[i][n-1], 0);
    for (int j=n-2; j>=0; --j) dp[m-1][j]=Math.max(dp[m-1][j+1]-dungeon[m-1][j], 0);

    for (int i=m-2; i>=0; --i) 
      for (int j=n-2; j>=0; --j)
        dp[i][j]=Math.max(Math.min(dfs(i+1,j, m, n, dungeon), dfs(i, j+1, m, n, dungeon))-dungeon[i][j], 0);

    return dp[0][0]+1;
  }
}