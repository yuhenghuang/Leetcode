class BestTimeStockCooldown {
  public static void main(String[] args) {
    BestTimeStockCooldown obj = new BestTimeStockCooldown();
    System.out.println(obj.maxProfit(new int[] {1,4,2}));
  }
  public int maxProfit(int[] prices) {
    int N = prices.length;
    if (N<2)
      return 0;

    // two status at time t
    // 0: holding stock, 1: not holding stock
    int[][] dp = new int[N][2];

    dp[0][0] = -prices[0];
    dp[0][1] = 0;

    dp[1][0] = -Math.min(prices[0], prices[1]);
    dp[1][1] = Math.max(0, prices[1]-prices[0]);

    for (int i=2; i<N; ++i) {
      // do nothing or buy today's stock
      dp[i][0] = Math.max(dp[i-1][0], dp[i-2][1]-prices[i]);

      // do nothing or sell stock at today's price
      dp[i][1] = Math.max(dp[i-1][1], dp[i-1][0]+prices[i]);
    }

    return dp[N-1][1];
  }

  boolean[][] seen;
  int[][] memo;
  public int maxProfitOn2(int[] prices) {
    int N = prices.length;
    if (N==0) return 0;
    memo = new int[N][N];
    seen = new boolean[N][N];
    return dp(0, N-1, prices);
  }

  int dp(int i, int j, int[] prices) {
    if (i>j) return 0;
    if (seen[i][j]) return memo[i][j];
    int res = Math.max(prices[j] - prices[i], 0);

    for (int k=i; k<=j; ++k)
      res = Math.max(res, dp(i, k-1, prices) + dp(k+1, j, prices));

    seen[i][j] = true;
    memo[i][j] = res;
    return res;
  }
}