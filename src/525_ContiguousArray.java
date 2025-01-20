import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class ContiguousArray {
  public int findMaxLength(int[] nums) {
    int N = nums.length;
    int[] memo = new int[2*N+1];
    Arrays.fill(memo, -2);
    memo[N] = -1;

    int res=0, cumsum=0;
    for (int i=0; i<N; ++i) {
      cumsum+=nums[i];
      int diff = (cumsum<<1)-i-1+N;
      if (memo[diff]>-2)
        res = Math.max(res, i-memo[diff]);
      else
        memo[diff] = i;
    }
    return res;
  }

  public int findMaxLengthMap(int[] nums) {
    Map<Integer, Integer> map = new HashMap<>();
    map.put(0, -1);

    int res=0, cumsum=0;
    for (int i=0; i<nums.length; ++i) {
      cumsum+=nums[i];
      if (map.containsKey((cumsum << 1)-i-1)) 
        res = Math.max(res, i - map.get((cumsum << 1)-i-1));
      else
        map.put((cumsum << 1)-i-1, i);
    }
    return res;
  }
}