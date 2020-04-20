public class ArrayProductExptSelf {
  public static void main(String[] args) {
    ArrayProductExptSelf obj = new ArrayProductExptSelf();
    int[] res = obj.productExceptSelf(new int[] {1,2,3,4});
    for (int num: res)
      System.out.print(num+"\t");
  }
  public int[] productExceptSelf(int[] nums) {
    int n = nums.length;
    int[] forward=new int[n], backward=new int[n];

    forward[0]=1;
    for (int i=1; i<n; ++i)
      forward[i]=forward[i-1]*nums[i-1];
    
    backward[n-1]=1;
    for (int i=n-2; i>=0; --i)
      backward[i]=backward[i+1]*nums[i+1];

    for (int i=0; i<n; ++i)
      nums[i]=forward[i]*backward[i];
    return nums;
  }
}