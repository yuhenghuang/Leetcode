public class PredictWinner {
  public static void main(String[] args) {
    PredictWinner obj = new PredictWinner();
    System.out.println(obj.PredictTheWinner(new int[] {0}));
  }

  int s1, s2;
  int[][] memo1, memo2;
  public boolean PredictTheWinner(int[] nums) {
    int n=nums.length;
    memo1 = new int[n][n];
    memo2 = new int[n][n];
    s1 = minimax(0, n-1, true, nums);
    s2 = -s1;
    for (int num : nums)
      s2+=num;
    return s1>=s2?true:false;
  }

  public int minimax(int i, int j, boolean p1, int[] nums) {
    if (i>j) return 0;
    if (p1) {
      if (memo1[i][j]>0) return memo1[i][j];
      memo1[i][j] = Math.max(nums[i]+minimax(i+1, j, false, nums), nums[j]+minimax(i, j-1, false, nums));
      return memo1[i][j];
    }
    else {
      if (memo2[i][j]>0) return memo2[i][j];
      memo2[i][j] = Math.min(minimax(i+1, j, true, nums), minimax(i, j-1, true, nums));
      return memo2[i][j];
    }
  }
}