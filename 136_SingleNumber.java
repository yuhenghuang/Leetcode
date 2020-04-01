class SingleNumber {
  public static void main(String[] args) {
    SingleNumber obj = new SingleNumber();
    int[] nums = new int[] {4,1,2,1,2};
    System.out.println(obj.singleNumber(nums));
  }
  public int singleNumber(int[] nums) {
    int res = 0;
    for (int num : nums)
      res ^= num;
    return res;
  }
}