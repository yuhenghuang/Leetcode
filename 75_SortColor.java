import java.util.Arrays;

class SortColor {
  public static void main(String[] args) {
    SortColor obj = new SortColor();
    int[] nums = new int[] {2,0,2,1,1,0};
    obj.sortColors(nums);
    System.out.println(Arrays.toString(nums));
  }
  public void sortColors(int[] nums) {
    int N = nums.length;
    if (N==0) return;
    int p=0, q=N-1, i=0;
    while (i<=q) {
      if (nums[i]==0) {
        nums[i++] = nums[p];
        nums[p++] = 0;
      }
      else if (nums[i]==2) {
        nums[i] = nums[q];
        nums[q--] = 2;
      }
      else
        ++i;
    }
  }
}