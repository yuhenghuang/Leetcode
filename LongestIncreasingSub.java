//import java.util.Map;
import java.util.TreeMap;

public class LongestIncreasingSub {
  public static void main(String[] args) {
    LongestIncreasingSub obj = new LongestIncreasingSub();
    System.out.println(obj.lengthOfLIS(new int[] {1, 2, 3}));
  }

  public int lengthOfLIS(int[] nums) {
    TreeMap<Integer, Integer> tree = new TreeMap<>();
    int n=nums.length;
    if (n==0) return 0;
    tree.put(nums[0], 0);
    for (int i=1; i<n; ++i) {
      Integer key = tree.ceilingKey(nums[i]);
      if (key!=null) tree.remove(key);
      tree.put(nums[i], i);
    }
    return tree.size();
  }


  public int lengthOfLISOn(int[] nums) {
    int n=nums.length;
    int[] dp = new int[n];
    for (int i=n-1; i>=0; --i) {
      int res=0;
      for (int j=i+1; j<n; j++) {
        if (nums[j]>nums[i]) res=Math.max(res, dp[j]);
      }
      dp[i]=res+1;
    }

    int ans=0;
    for (int i=0; i<n; ++i)
      if (dp[i]>ans)
        ans=dp[i];
    return ans;
  }
}