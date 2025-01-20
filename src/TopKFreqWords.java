import java.util.*;

public class TopKFreqWords {
  public static void main(String[] args) {
    TopKFreqWords obj = new TopKFreqWords();
    System.out.println(obj.topKFrequent(new String[] {"i", "love", "leetcode", "i", "love", "coding"}, 2));
  }
  public List<String> topKFrequent(String[] words, int k) {
    Map<String, Integer> map = new HashMap<>();
    for (String s : words)
      map.put(s, map.getOrDefault(s, 0)+1);

    criteria comp = new criteria(map);
    PriorityQueue<String> heap = new PriorityQueue<>(k, comp);
    heap.addAll(map.keySet());

    List<String> res = new ArrayList<>();
    while (k-->0)
      res.add(heap.poll());
    return res;
  }

  class criteria implements Comparator<String> {
    Map<String, Integer> map;
    criteria(Map<String, Integer> m) {
      map = m;
    }
    @Override
    public int compare(String o1, String o2) {
      if (map.get(o1)<map.get(o2))
        return 1;
      else if (map.get(o1)>map.get(o2))
        return -1;
      else {
        return o1.compareTo(o2);
      }
    }
  }
}