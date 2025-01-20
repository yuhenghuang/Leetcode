import java.util.Arrays;

class NextPermutation {
  public static void main(String[] args) {
    NextPermutation obj = new NextPermutation();
    int[] nums = new int[] {2,3,1};
    obj.nextPermutation(nums);
    System.out.println(Arrays.toString(nums));
  }
  public void nextPermutation(int[] nums) {
    int n=nums.length, i=n-2;
    while (i>=0 && nums[i]>=nums[i+1]) i--;
    if (i==0) {
      int j = i+1;
      while (j<n && nums[j]>nums[i]) j++;
      swap(nums, i, j-1);
    }
    reverse(nums, i+1, n-1);
  }

  private void swap(int[] nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }

  private void reverse(int[] nums, int i, int j) {
    while (i<j) {
      swap(nums, i, j);
      i++;
      j--;
    }
  }
}