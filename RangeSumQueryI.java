public class RangeSumQueryI {
  //.....
}


class NumArray {
  int[] cumSum;
  public NumArray(int[] nums) {
    cumSum = new int[nums.length+1];
    for (int i=0; i<nums.length; ++i)
      cumSum[i+1] = cumSum[i]+nums[i];
  }
  
  public int sumRange(int i, int j) {
    return cumSum[j+1] - cumSum[i];
  }
}