public class MissingNumber {
  public static void main(String[] args) {
    MissingNumber obj = new MissingNumber();
    System.out.println(obj.missingNumber(new int[] {}));
  }
  public int missingNumber(int[] nums) {
    int n=nums.length;
    for (int i=0; i<n; ++i) {
      int idx=i, num=nums[idx];
      while (num!=n && num!=idx) {
        idx=num;
        num=nums[idx];
        nums[idx]=idx;
      }
    }
    for (int i=0; i<n; ++i)
      if (nums[i]!=i)
        return i;
    return n;
  }
}