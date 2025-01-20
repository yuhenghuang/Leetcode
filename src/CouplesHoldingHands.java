import java.util.Map;
import java.util.HashMap;

public class CouplesHoldingHands {
  public int minSwapsCouples(int[] row) {
    int N = row.length/2;
    Map<Integer, Integer> graph = new HashMap<>();
    for (int i=0; i<N; ++i) {
      graph.put(row[2*i], row[2*i+1]);
      graph.put(row[2*i+1], row[2*i]);
    }

    int res=0;
    return res;
  }
}