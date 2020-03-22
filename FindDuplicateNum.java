public class FindDuplicateNum {
  public static void main(String[] args) {
    FindDuplicateNum obj = new FindDuplicateNum();
    System.out.println(obj.findDuplicate(new int[] {2,2,2,2,2}));
  }
  public int findDuplicate(int[] nums) {
    int n=nums.length;
    for (int i=0; i<n; ++i) {
      
    }
    return -1;
  }

  public int findDuplicateOn2(int[] nums) {
    int n=nums.length;
    for (int i=0; i<n; ++i)
      for (int j=i+1; j<n; ++j)
        if (nums[i]==nums[j])
          return nums[i];
    return -1;
  }
}