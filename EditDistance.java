public class EditDistance {
  public static void main(String[] args) {
    EditDistance obj = new EditDistance();
    System.out.println(obj.minDistance("intention", "execution"));
  }
  int[][] memo;
  public int minDistance(String word1, String word2) {
    int m=word1.length(), n=word2.length();
    memo = new int[m+1][n+1];
    for (int i=0; i<=m; ++i) memo[i][0]=i;
    for (int j=0; j<=n; ++j) memo[0][j]=j;

    for (int i=1; i<=m; ++i)
      for (int j=1; j<=n; ++j)
        if (word1.charAt(i-1)==word2.charAt(j-1))
          memo[i][j]=memo[i-1][j-1];
        else 
          memo[i][j]=Math.min(memo[i-1][j-1], Math.min(memo[i][j-1], memo[i-1][j]))+1;
    return memo[m][n];
  }
}