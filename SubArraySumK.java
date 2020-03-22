import java.util.Map;
import java.util.HashMap;

public class SubArraySumK {
  public int subarraySum(int[] nums, int k) {
    int sum=0, res=0;
    Map<Integer, Integer> map = new HashMap<>();
    map.put(0, 1);
    for (int num : nums) {
      sum+=num;
      res+=map.getOrDefault(sum-k, 0);
      map.put(sum, map.getOrDefault(sum, 0) + 1);
    }
    return res;
  }
}