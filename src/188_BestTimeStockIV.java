class BestTimeStockIV {
  public static void main(String[] args) {
    BestTimeStockIV obj = new BestTimeStockIV();
    System.out.println(obj.maxProfit(2, new int[] {3,2,6,5,0,3}));
  }
  public int maxProfit(int k, int[] prices) {
    int N = prices.length;
    if (k==0 || N<2) return 0;
    k = Math.min(k, N/2);
    int[] prev = new int[k*2+1], next = new int[k*2+1];

    for (int j=k; j>=1; j--)
      prev[j*2-1] = - prices[0];

    for (int i=1; i<N; ++i) {
      for (int j=1; j<=k; ++j) {
        next[j*2-1] = Math.max(prev[j*2-1], prev[j*2-2]-prices[i]);
        next[j*2] = Math.max(prev[j*2], prev[j*2-1] + prices[i]);
      }
      prev = next;
    }
    return prev[k*2];
  }
}