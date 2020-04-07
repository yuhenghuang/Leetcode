class BurstBallons {
  public static void main(String[] args) {
    BurstBallons obj = new BurstBallons();
    int[] nums = new int[] {3,1,5,8};
    System.out.println(obj.maxCoins(nums));
  }

  public int maxCoins(int[] nums) {
    // Takeaway:
    // Clarify the definition of DP!!
    // Corns gained when clear ALL balloons between l and r
    // ALL!!!!!!!!!!!!
    int n = nums.length;;
    int[] ex = new int[n+2];
    ex[0] = ex[n+1] = 1;
    for (int i=0; i<n; ++i)
      ex[i+1] = nums[i];

    int[][] memo = new int[n+2][n+2];

    for (int r=1; r<=n; ++r) {
      for (int l=r; l>0; --l) {
        for (int p=r; p>=l; --p) {
          memo[l][r] = Math.max(memo[l][p-1] + memo[p+1][r] + ex[l-1] * ex[p] * ex[r+1], memo[l][r]);
        }
      }
    }
    return memo[1][n];
  }
}