import java.util.Arrays;

class MinCostForTickets {
  public static void main(String[] args) {
    int[] days = new int[] {1,4,6,7,8,20};
    int[] costs = new int[] {2,7,15};

    MinCostForTickets obj = new MinCostForTickets();
    System.out.println(obj.mincostTickets(days, costs));
  }
  public int mincostTickets(int[] days, int[] costs) {
    int n = days.length;
    int[] dp = new int[n];

    int res = 0, idx;
    int[] passes = new int[] {1, 7, 30};
    for (int i=0; i<n; ++i) {
      res = Integer.MAX_VALUE;
      for (int j=0; j<3; ++j) {
        idx = Arrays.binarySearch(days, days[i]-passes[j]);
        if (idx>=0)
          res = Math.min(res, dp[idx] + costs[j]);
        else {
          idx = -idx - 2;
          res = Math.min(res, (idx<0 ? 0 : dp[idx]) + costs[j]);
        }
      }
      dp[i] = res;
    }

    return res;
  }
}