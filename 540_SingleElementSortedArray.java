class SingleElementSortedArray {
  public int singleNonDuplicate(int[] nums) {
    int l=0, r=nums.length;
    while (l<r) {
      int m = l + (r-l) / 2;
      m -= m%2;
      if (nums[m]==nums[m+1])
        l = m+2;
      else
        r = m;
    }
    return nums[l];
  }
}