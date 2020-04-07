class RotateImage {
  public void rotate(int[][] matrix) {
    int n=matrix.length;

    for (int i=0; i<n; ++i)
      for (int j=0; j<i; ++j) {
      int temp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = temp;
      }

    for (int i=0; i<n; ++i)
        reverse(matrix[i], 0, n-1);
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