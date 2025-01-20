public class FirstMissingPositive {
  public int firstMissingPositive(int[] nums) {
    int N=nums.length;
    for (int i=0; i<N; ++i) {
      int num = nums[i], idx=i;
      while (num-1!=idx && num>0 && num<=N) {
        idx=num-1;
        int num_temp=nums[idx];
        nums[idx]=num;
        num=num_temp;
      }
    }
    for (int i=0; i<N; ++i)
      if (nums[i]!=i+1)
        return i+1;
    return N+1;
  }
}