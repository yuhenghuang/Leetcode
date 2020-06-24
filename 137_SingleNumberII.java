class SingleNumberII {
  public static void main(String[] args) {
    SingleNumberII obj = new SingleNumberII();
    System.out.println(obj.singleNumber(new int[] {0,1,0,1,0,1,99}));
  }
  public int singleNumber(int[] nums) {
    int low=0, high=0;
    for (int num : nums) {
      high = low & (high ^ num);
      low  = high | (low ^ num);
    }
    return low;
  }
}