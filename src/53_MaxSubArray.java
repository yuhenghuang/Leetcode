class MaxSubArray {
  public static void main(String[] args) {
    MaxSubArray obj = new MaxSubArray();
    System.out.println(obj.maxSubArray(new int[] {-2,1,-3,4,-1,2,1,-5,4}));
  }

  public int maxSubArray(int[] nums) {
    return dv(nums, 0, nums.length-1);
  }

  private int findMid(int l, int r) {
    return l + (r-l)/2;
  }

  private int dv(int[] nums, int l, int r) {
    if (l==r) 
      return nums[l];
    int m = findMid(l, r);
    return Math.max(Math.max(dv(nums, l, m), 
                             dv(nums, m+1, r)), 
                    dv2(nums, l, m, r));
  }

  private int dv2(int[]nums, int l, int m, int r) {
    int left = Integer.MIN_VALUE;
    int sum = 0;
    for (int i=m; i>=l; --i) {
      sum += nums[i];
      if (sum>left) left = sum;
    }

    int right = Integer.MIN_VALUE;
    sum = 0;
    for (int i=m+1; i<=r; ++i) {
      sum +=nums[i];
      if (sum>right) right = sum;
    }
    return left+right;
  }



  public int maxSubArrayOn(int[] nums) {
    int res = Integer.MIN_VALUE, sum=0;
    for (int num : nums) {
      sum+=num;
      res = Math.max(sum, res);
      if (sum<0) sum=0;
    }
    return res;
  }
}