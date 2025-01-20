public class JumpGameII {
  public static void main(String[] args) {
    JumpGameII obj = new JumpGameII();
    System.out.println(obj.jump(new int[] {2,3,0,1,4}));
  }
  public int jump(int[] nums) {
    int N = nums.length;
    int memo[] = new int[N];
    for (int i=N-2; i>=0; --i) {
      int res=100000000;
      for (int j=i+nums[i]; j>i; j--) {
        if (j<N-1) res = Math.min(res, 1+memo[j]);
        else {res=1; break;}
        System.out.println(i+" "+j+" "+res);
      }
      memo[i]=res;
    }
    //for (int num : memo) System.out.println(num);
    return memo[0];
  }
}