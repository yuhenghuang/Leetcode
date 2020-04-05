class BestTimeStockII {
  public int maxProfit(int[] prices) {
    int n=prices.length, l=0, h=0, res=0;
    while (l<n-1) {
      while (l<n-1 && prices[l] >= prices[l+1]) l++;
      h = l;
      while (h<n-1 && prices[h] <= prices[h+1]) h++;
      res += prices[h]-prices[l];
      l = h+1;
    }
    return res;
  }
}