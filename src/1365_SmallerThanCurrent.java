import java.util.Arrays;

class SmallerThanCurrent {
  public int[] smallerNumbersThanCurrent(int[] nums) {
    int[] sorted = nums.clone();
    Arrays.sort(sorted);
    for (int i=0; i<nums.length; ++i) {
      int count = Arrays.binarySearch(sorted, nums[i]);
      if (count<0) 
        count = 1 - count;
      do {
        count--;
      } while (count>=0 && count>=nums[i]);
      
      nums[i]=count+1;
    }
    return nums;
  }
}