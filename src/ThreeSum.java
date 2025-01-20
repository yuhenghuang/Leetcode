import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Map;
import java.util.HashMap;
import java.util.Set;
import java.util.HashSet;

public class ThreeSum {
  public List<List<Integer>> threeSum(int[] nums) {
    Set<List<Integer>> res = new HashSet<>();
    Arrays.sort(nums);
    int n = nums.length;
    for (int i=0; i<n-2; ++i) {
      int x = nums[i];
      for (int j=i+1; j<n-1; ++j) {
        int y = nums[j];
        if (Arrays.binarySearch(nums, j+1, n-1, -x-y)>=0) {
          res.add(new ArrayList<>(List.of(x, y, -x-y)));
        }
      }
    }
    return new ArrayList<>(res);
  }

  public List<List<Integer>> threeSumMap(int[] nums) {
    List<List<Integer>> res = new ArrayList<>();
    Map<Integer, Integer> map = new HashMap<>();
    for (int num : nums)
      map.put(num, map.getOrDefault(num, 0)+1);

    for (int x : map.keySet()) {
      map.put(x, map.get(x)-1);
      for (int y : map.keySet()) {
        if (y>=x && map.get(y)>0) {
          map.put(y, map.get(y)-1);
          int z = -x-y;
          if (z>=y && map.containsKey(z) && map.get(z)>0) {
            res.add(new ArrayList<>(List.of(x, y, z)));
          }
          map.put(y, map.get(y)+1);
        }
      }
      map.put(x, map.get(x)+1);
    }
    return res;
  }
}