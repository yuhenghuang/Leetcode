import java.util.*;

public class CriticalConnections {
  public static void main(String[] args) {
    CriticalConnections obj = new CriticalConnections();
    //int[][] col = new int[][] {{0, 1}, {1, 2}, {2, 0}, {1, 3}};
    System.out.println(obj.criticalConnections(4, new ArrayList<>(List.of())));
  }
  int idx=1;
  int[] lowlink, index;
  Map<Integer, List<Integer>> map;
  List<List<Integer>> res;
  public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
    lowlink = new int[n];
    index = new int[n];
    res = new ArrayList<>();

    map = new HashMap<>();
    for (int i=0; i<n; i++)
      map.put(i, new ArrayList<>());

    for (List<Integer> ls : connections) {
      map.get(ls.get(0)).add(ls.get(1));
      map.get(ls.get(1)).add(ls.get(0));
    }

    for (int i=0; i<n; ++i)
      if (index[i]==0)
        dfs(i, -1);
    return res;
  }

  public void dfs(int v, int p) {
    lowlink[v]=idx;
    index[v]=idx++;
    for (int next : map.get(v))
      if (next==p) continue;
      else if (index[next]==0) {
        dfs(next, v);
        lowlink[v]=Math.min(lowlink[v], lowlink[next]);
        if (lowlink[next]>index[v])
          res.add(new ArrayList<>(List.of(v, next)));
      }
      else 
        lowlink[v]=Math.min(lowlink[v], index[next]);
  }
}