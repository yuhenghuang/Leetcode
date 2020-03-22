import java.util.*;

public class SortCharbyFreq {
  public String frequencySort(String s) {
    Map<Character, Integer> freq = new HashMap<>();
    for (int i=0; i<s.length(); ++i) {
      freq.put(s.charAt(i), freq.getOrDefault(s.charAt(i), 0)+1);
    }
    StringBuilder res= new StringBuilder("");
    //TreeMap<Integer, Set<Character>> treemap = new TreeMap<>();
    PriorityQueue<Map.Entry<Character, Integer>> heap = new PriorityQueue<>(
      (info1, info2) -> info2.getValue() - info1.getValue()
    );
    heap.addAll(freq.entrySet());
    while (!heap.isEmpty()) {
      Map.Entry<Character, Integer> entry = heap.poll();
      int occur=entry.getValue();
      String c = entry.getKey().toString();
      res.append(c.repeat(occur));
    }
    return res.toString();
  }
}