import java.util.ArrayList;
//import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;

class CheapestFlightsInK {
  public static void main(String[] args) {
    CheapestFlightsInK obj = new CheapestFlightsInK();
    int[][] edges = new int[][] {{0,1,1}, {0,2,5}, {1,2,1}, {2,3,1}};
    System.out.println(obj.findCheapestPrice(4, edges, 0, 3, 1));
  }
  public int findCheapestPrice(int n, int[][] flights, int src, int dst, int K) {
    int[][] prices = new int[n][n];
    Map<Integer, List<Integer>> map = new HashMap<>();
    for (int i=0; i<n; ++i)
      map.put(i, new ArrayList<>());

    for (int[] f : flights) {
      prices[f[0]][f[1]] = f[2];
      map.get(f[0]).add(f[1]);
    }
    System.out.println(map);

    boolean[][] seen = new boolean[n][K+3];
    Queue<int[]> heap = new PriorityQueue<>(
      (a, b) -> a[2] - b[2]
    );

    heap.offer(new int[] {src, 0, 0}); // location, # of flights, expense
    while (!heap.isEmpty()) {
      int[] record = heap.poll();
      //System.out.println(Arrays.toString(record));
      if (record[1]>=K+2 || seen[record[0]][record[1]]) continue;
      if (record[0]==dst) return record[2];
      seen[record[0]][record[1]] = true;
      for (int next : map.get(record[0])) 
        if (!seen[next][record[1]+1])
          heap.offer(new int[] {next, record[1]+1, record[2]+prices[record[0]][next]});
    }
    return -1;
  }
}