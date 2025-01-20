import java.util.Map;
import java.util.HashMap;
import java.util.Queue;
import java.util.PriorityQueue;
import java.util.List;
import java.util.ArrayList;

public class TopKFreqNum {
  public List<Integer> topKFrequent(int[] nums, int k) {
    List<Integer> res = new ArrayList<>();
    Map<Integer, Integer> map = new HashMap<>();
    Queue<Integer> queue = new PriorityQueue<>(
      (a, b) -> map.get(b)-map.get(a)
    );
    for (int num: nums)
      map.put(num, map.getOrDefault(num, 0)+1);

    for (int num: map.keySet())
      queue.add(num);

    while (!queue.isEmpty() && k-->0)
      res.add(queue.poll());

    return res;
  }
}