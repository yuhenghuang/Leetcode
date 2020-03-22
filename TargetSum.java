import java.util.Arrays;

public class TargetSum {
  public static void main(String[] args) {
    TargetSum obj = new TargetSum();
    int[] nums = new int[] {1,1,1,1,1};
    System.out.println(obj.findTargetSumWays(nums, 3));
  }

  int n, target;
  int memo[][];
  public int findTargetSumWays(int[] nums, int S) {
    n = nums.length;
    target = S;
    memo = new int[n][2001];
    for (int[] row : memo)
      Arrays.fill(row, -1);

    return dp(0, 0, nums);
  }

  public int dp(int cursum, int idx, int[] nums) {
    if (idx==n) {
      if (cursum==target) return 1;
      else return 0;
    }
    if (memo[idx][cursum+1000]!=-1)
      return memo[idx][cursum+1000];
    
    int add = dp(cursum+nums[idx], idx+1, nums);
    int sub = dp(cursum-nums[idx], idx+1, nums);
    memo[idx][cursum+1000] = add+sub;
    return memo[idx][cursum+1000];
  }

  int res;
  public int findTargetSumWaysSlow(int[] nums, int S) {
    n = nums.length;
    target = S;
    res = 0;
    dfs(0, 0, nums);
    return res;
  }

  public void dfs(int cursum, int idx, int[] nums) {
    if (idx==n) {
      if (cursum==target) res++;
      return;
    }
    dfs(cursum+nums[idx], idx+1, nums);
    dfs(cursum-nums[idx], idx+1, nums);
  }
}