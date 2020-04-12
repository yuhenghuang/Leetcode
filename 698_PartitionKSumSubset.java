import java.util.Arrays;

class PartitionKSumSubset {
  public static void main(String[] args) {
    PartitionKSumSubset obj = new PartitionKSumSubset();
    int[] arr = new int[] {129,17,74,57,1421,99,92,285,1276,218,1588,215,369,117,153,22};
    System.out.println(obj.canPartitionKSubsets(arr, 3));
  }

  int n, k, target;
  int[] nums, memo;
  boolean[] seen;
  public boolean canPartitionKSubsets(int[] nums, int k) {
    int N = nums.length;
    Arrays.sort(nums);
    int sum = Arrays.stream(nums).sum();
    int target = sum / k;
    if (sum % k > 0 || nums[N - 1] > target) return false;

    int maxLen = 1 << N;
    boolean[] dp = new boolean[maxLen];
    int[] total = new int[maxLen];
    dp[0] = true;

    for (int i=0; i<maxLen; ++i) {
      if (!dp[i]) continue;
      for (int j=0; j<N; ++j) {
        int next = i | (1 << j);
        if (i!=next && !dp[next]) {
          if (nums[j] <= target - (total[i] % target)) {
            dp[next] = true;
            total[next] = total[i] + nums[j];
          }
          else 
            break; // sorted...
        }
      }
    }
    return dp[maxLen-1];
  }

  public boolean dp(int rem) {
    if (rem==0) {
      boolean b = true;
      for (int res: memo)
        if (res!=0)
          b = false;
      return b;
    }

    for (int i=0; i<n; ++i) {
      if (seen[i]) continue;
      for (int j=0; j<k; ++j) {
        if (memo[j]==0 || memo[j]<nums[i]) continue;
        seen[i] = true;
        memo[j]-=nums[i];
        if (dp(rem-1))
          return true;
        memo[j]+=nums[i];
        seen[i] = false;
      }
    }
    return false;
  }

  public boolean canPartitionKSubsetsDFS(int[] nums, int k) {
    int sum=0;
    n = nums.length;
    for (int i=0; i<n; ++i)
      sum+=nums[i];
    
    if (sum % k !=0) return false;

    target = sum / k;
    this.nums = nums;
    seen = new boolean[n];
    return dfs(n, target);
  }

  public boolean dfs(int rem, int ct) {
    if (rem==0 && ct==0) return true;

    if (ct==0)
      ct=target;

    for (int i=0; i<n; ++i) {
      if (seen[i] || nums[i]>ct)
        continue;

      seen[i]=true;
      if (dfs(rem-1, ct-nums[i]))
        return true;
      seen[i]=false;
    }
    return false;
  }
}