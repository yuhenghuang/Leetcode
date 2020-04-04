import java.util.Arrays;

class MoveZeroes {
  public static void main(String[] args) {
    MoveZeroes obj = new MoveZeroes();
    int[] nums = new int[] {0,1,0,3,12};
    obj.moveZeroes(nums);
    System.out.println(Arrays.toString(nums));
  }
  public void moveZeroes(int[] nums) {
    int p=0;
    for (int i=0; i<nums.length; ++i) {
      if (nums[i]==0) continue;
      if (i>p) {
        nums[p] = nums[i];
        nums[i] = 0;
      }
      p++;
    }
  }
}