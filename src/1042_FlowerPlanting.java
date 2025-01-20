import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class FlowerPlanting {
  public static void main(String[] args) {
    FlowerPlanting obj = new FlowerPlanting();
    int[][] paths = new int[][] {{1,2},{3,4}};
    int[] res = obj.gardenNoAdj(4, paths);
    for (int i: res)
      System.out.print(i+"\t");
  }
  boolean[][] seen;
  Map<Integer, List<Integer>> graph;
  public int[] gardenNoAdj(int N, int[][] paths) {
    seen = new boolean[N][5];
    graph = new HashMap<>();
    for (int i=0; i<N; i++)
      graph.put(i, new ArrayList<>());
    for (int[] edge : paths) {
      graph.get(edge[0]-1).add(edge[1]-1);
      graph.get(edge[1]-1).add(edge[0]-1);
    }

    for (int i=0; i<N; ++i)
      if (!seen[i][0])
        dfs(i);
    
    int[] res = new int[N];
    for (int i=0; i<N; ++i) 
      for (int j=1; j<=4; ++j)
        if (!seen[i][j]) {
          res[i]=j;
          break;
        }
    return res;
  }

  public boolean dfs(int v) {
    if (seen[v][0]) return true;
    seen[v][0]=true;
    for (int i=1; i<=4; ++i) {
      if (seen[v][i]) continue;
      for (int w: graph.get(v)) {
        seen[w][i]=true;
      }
      boolean flag=true;
      for (int w: graph.get(v)) {
        flag=dfs(w);
        if (!flag) break;
      }

      if (flag) return true;

      for (int w: graph.get(v)) {
        seen[w][i]=false;
      }
    }
    seen[v][0]=false;
    return false;
  }
}