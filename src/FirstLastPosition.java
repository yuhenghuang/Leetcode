import java.util.Arrays;

public class FirstLastPosition {
  public int[] searchRange(int[] nums, int target) {
    int idx=Arrays.binarySearch(nums, target);
    if (idx<0) return new int[] {-1, -1};
    int first = idx;
    while (first>0 && nums[first-1]==nums[first]) first--;
    int last = idx;
    while (last<nums.length-1 && nums[last]==nums[last+1]) last++;
    return new int[] {first, last};
  }
}