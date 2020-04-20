class SearchInRotatedArray {
  public static void main(String[] args) {
    SearchInRotatedArray obj = new SearchInRotatedArray();
    int[] nums = LeetcodeUtil.arrayIntParser("[1,0]");
    System.out.println(obj.search(nums, 0));
  }
  public int search(int[] nums, int target) {
    int l=0, r=nums.length-1;
    if (r<0) return -1;
    while (l<r) {
      int m = l + (r-l) / 2;
      if (target>=nums[0]) {
        if (nums[m]<nums[l] || nums[m]>=target)
          r = m;
        else
          l = m+1;
      }
      else {
        if (nums[m]>nums[r] || nums[m]<target)
          l = m+1;
        else 
          r = m;
      }
    }

    return nums[l]==target?l:-1;
  }
}