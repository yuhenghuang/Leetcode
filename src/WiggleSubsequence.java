public class WiggleSubsequence {
  public static void main(String[] args) {
    WiggleSubsequence obj = new WiggleSubsequence();
    System.out.println(obj.wiggleMaxLength(new int[] {1,7,4,9,2,5}));
  }
  public int wiggleMaxLength(int[] nums) {
    int n=nums.length, res=0;
    int idx=0;
    //boolean up=false;
    while (idx<n-1 && nums[idx]==nums[idx+1]) idx++;
    //if (idx<n-1) up=nums[idx]<nums[idx+1];
    while (idx<n) {
      //if (up)
    }
    return res;
  }
}