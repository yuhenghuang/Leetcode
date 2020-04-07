class JumpGame {
  public static void main(String[] args) {
    JumpGame obj = new JumpGame();
    System.out.println(obj.canJump(new int[] {2,3,1,1,4}));
  }
  public boolean canJump(int[] nums) {
    int n=nums.length-1, next=0;
    for (int i=0; i<=n; ++i) {
      next = Math.max(next, i + nums[i]);
      if (next>=n) return true;
      if (i==next) break; 
    }
    return false;
  }

  public boolean canJumpDP(int[] nums) {
    int n=nums.length;
    boolean[] dp = new boolean[n];
    dp[n-1] = true;
    for (int i=n-2; i>=0; --i) {
      for (int j=1; j<=nums[i]; ++j)
        if (dp[i+j]) {
          dp[i] = true;
          break;
        }
    }
    return dp[0];
  }
}