public class MinSubarraySum {
  public static void main(String[] args) {
    MinSubarraySum obj = new MinSubarraySum();
    System.out.println(obj.minSubArrayLen(7, new int[] {2,3,1,2,4,3}));
  }
  public int minSubArrayLen(int s, int[] nums) {
    int res=Integer.MAX_VALUE, N=nums.length;
    int st=0, ed=0, sum=0;
    while (st<N) {
      while(ed<N && sum<s) sum+=nums[ed++];
      if (sum>=s) res=Math.min(res, ed-st);
      sum-=nums[st++];
    }
    return res==Integer.MAX_VALUE?0:res;
  }
}