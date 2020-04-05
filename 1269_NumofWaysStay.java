class NumofWaysStay {
  public static void main(String[] args) {
    NumofWaysStay obj = new NumofWaysStay();
    System.out.println(obj.numWays(27, 7));
  }
  public int numWays(int steps, int arrLen) {
    int mod = (int) 1e9 + 7, n = Math.min(1+steps/2, arrLen);
    if (n<2) return n;
    long[][] dp = new long[steps+1][n];
    dp[0][0] = 1;
    for (int i=1; i<=steps; ++i) {
      dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % mod;
      dp[i][n-1] = (dp[i-1][n-1] + dp[i-1][n-2]) % mod;
      for (int j=1; j<n-1; ++j)
        dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]) % mod;
    }
    return (int) dp[steps][0];
  }
}