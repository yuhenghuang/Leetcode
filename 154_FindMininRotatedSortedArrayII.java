class FindMinInRotatedSortedArrayII {
  public static void main(String[] args) {
    FindMinInRotatedSortedArrayII obj = new FindMinInRotatedSortedArrayII();
    int[] nums = new int[] {1, 3,3,3};
    System.out.println(obj.findMin(nums));
  }
  public int findMin(int[] nums) {
    int l=0, r=nums.length-1, m;
    while (l<r) {
      m = l + (r-l)/2;
      if (nums[m]>nums[r])
        l = m+1;
      else if (nums[m]<nums[r])
        r = m;
      else
        --r;
    }
    return nums[l];
  }
}