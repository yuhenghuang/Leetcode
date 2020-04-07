import java.util.HashMap;
import java.util.Map;

class CountingElements {
  public static void main(String[] args) {
    CountingElements obj = new CountingElements();
    int[] nums = new int[] {1,1,2,2};
    System.out.println(obj.countElements(nums));
  }
  public int countElements(int[] arr) {
    Map<Integer, Integer> map = new HashMap<>();
    for (int num : arr) 
      map.put(num, map.getOrDefault(num, 0) + 1);

    int res=0;
    for (int key : map.keySet())
      if (map.containsKey(key+1))
        res+=map.get(key);
    return res;
  }
}