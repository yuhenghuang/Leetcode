import java.util.HashSet;
import java.util.Set;

class SingleNumberIII {
  public int[] singleNumber(int[] nums) {
    Set<Integer> set = new HashSet<>();
    for (int num : nums) {
      if (!set.contains(num))
        set.add(num);
      else
        set.remove(num);
    }

    int[] res = new int[2];
    int idx = 0;
    for (int num : set)
      res[idx++] = num;
    return res;
  }
}