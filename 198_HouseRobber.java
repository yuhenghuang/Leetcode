import java.io.FileInputStream;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

class HouseRobber {
  public static void main(String[] args) {
    HouseRobber obj = new HouseRobber();
    System.out.println(obj.rob(new int[] {2,7,9,3,1}));

    int[] nums = null;

    FileInputStream f = null;
    Scanner sc = null;
    try {
      f = new FileInputStream("Inputs/198_HouseRobber.txt");
      sc = new Scanner(f, "UTF-8");
      while (sc.hasNextLine()) {
        String line = sc.nextLine();
        line = line.replaceAll("[\\[\\] \s\t]+", "");
        String[] strs = line.split(",");
        nums = Arrays.stream(strs).mapToInt(Integer::parseInt).toArray();
      }
      
      if (sc.ioException()!=null)
        throw sc.ioException();

      if (f!=null)
        f.close();
    }
    catch (IOException e) {
      System.out.println("IO Exception detected.." + e);
    }
    finally {
      if (sc!=null)
        sc.close();
    }

    if (nums!=null)
      System.out.println(obj.rob(nums));
  }


  int n;
  int [] memo;
  public int rob(int[] nums) {
    n = nums.length;
    memo = new int[n];
    return dp(0, nums);
  }

  int dp(int idx, int[] nums) {
    if (idx>=n) return 0;
    if (memo[idx]>0) return memo[idx];

    memo[idx] = Math.max(nums[idx] + dp(idx+2, nums), dp(idx+1, nums));

    return memo[idx];
  }
}