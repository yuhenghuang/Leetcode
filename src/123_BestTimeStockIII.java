class BestTimeStockIII {
  public int maxProfit(int[] prices) {
    int n = prices.length;
    if (n<2) return 0;
    int[] forward = new int[n];
    int[] backward = new int[n];

    int low = prices[0];
    for (int i=1; i<n; ++i) {
      forward[i] = Math.max(forward[i-1], prices[i] - low);
      low = Math.min(low, prices[i]);
    }

    int high = prices[n-1];
    for (int i=n-2; i>=0; --i) {
      backward[i] = Math.max(backward[i+1], high - prices[i]);
      high = Math.max(high, prices[i]);
    }

    int res = Math.max(forward[n-1], backward[0]);
    for (int i=1; i<n; ++i)
      res = Math.max(res, forward[i-1] + backward[i]);

    return res;
  }
}