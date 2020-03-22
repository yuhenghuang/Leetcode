public class ArrayProductExptSelf {
  public static void main(String[] args) {
    ArrayProductExptSelf obj = new ArrayProductExptSelf();
    int[] res = obj.productExceptSelf(new int[] {});
    for (int num: res)
      System.out.print(num+"\t");
  }
  public int[] productExceptSelf(int[] nums) {
    int n = nums.length;
    int[] forward=new int[n+1], backward=new int[n+1];

    forward[0]=1;
    for (int i=0; i<n; ++i)
      forward[i+1]=forward[i]*nums[i];
    
    backward[n]=1;
    for (int i=n; i>0; --i)
      backward[i-1]=backward[i]*nums[i-1];

    for (int i=0; i<n; ++i)
      nums[i]=forward[i]*backward[i+1];
    return nums;
  }
}