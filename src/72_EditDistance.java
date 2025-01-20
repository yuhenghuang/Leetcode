class __EditDistance__ {
  public static void main(String[] args) {
    __EditDistance__ obj = new __EditDistance__();
    System.out.println(obj.minDistance("intention", "execution"));
  }
  public int minDistance(String word1, String word2) {
    int m = word1.length(), n = word2.length();
    int[][] memo = new int[m+1][n+1];
    for (int i=1; i<=m; ++i)
      memo[i][0] = i;
    for(int j=1; j<=n; ++j)
      memo[0][j] = j;

    for (int i=1; i<=m; ++i)
      for (int j=1; j<=n; ++j)
        if (word1.charAt(i-1)==word2.charAt(j-1))
          memo[i][j] = memo[i-1][j-1];
        else
          memo[i][j] = 1 + Math.min(memo[i-1][j-1], Math.min(memo[i-1][j], memo[i][j-1]));
    return memo[m][n];
  }
}