import java.util.HashMap;
import java.util.Hashtable;
import java.util.Map;

class SubArraySumEqK {
  public static void main(String[] args) {
    int[] nums = new int[] {1, 1, 1};
    SubArraySumEqK obj = new SubArraySumEqK();
    System.out.println(obj.subarraySum(nums, 2));
  }
  public int subarraySumMap(int[] nums, int k) {
    Hashtable <Integer, Integer> tb = new Hashtable<>();
    tb.put(0, 1);
    int sum=0, res=0;
    for (int i=0; i<nums.length; ++i) {
      sum+=nums[i];
      res+=tb.getOrDefault(sum-k, 0);
      tb.put(sum, tb.getOrDefault(sum, 0)+1);
    }
    return res;
  }

  public int subarraySum(int[] nums, int k) {
    Map <Integer, Integer> map = new HashMap<>();
    map.put(0, 1);
    int sum=0, res=0;
    for (int i=0; i<nums.length; ++i) {
      sum+=nums[i];
      res+=map.getOrDefault(sum-k, 0);
      map.put(sum, map.getOrDefault(sum, 0)+1);
    }
    return res;
  }
}