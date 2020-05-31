import java.util.ArrayList;
import java.util.List;

class PossibleBipartition {
  public static void main(String[] args) {
    PossibleBipartition obj = new PossibleBipartition();
    int[][] nums = LeetcodeUtil.arrayInt2dParser("[[1,2],[2,3],[3,4],[4,5],[1,5]]");
    System.out.println(obj.possibleBipartition(5, nums));
  }
  List<List<Integer>> graph;
  int[] colors;
  public boolean possibleBipartition(int N, int[][] dislikes) {
    graph = new ArrayList<>(N+1);
    colors = new int[N+1];
    for (int i=0; i<=N; ++i) 
      graph.add(new ArrayList<>());

    for (int[] edge : dislikes) {
      graph.get(edge[0]).add(edge[1]);
      graph.get(edge[1]).add(edge[0]);
    }

    for (int i=1; i<=N; ++i)
      if (colors[i]==0 && !dfs(i, 1))
        return false;

    return true;
  }

  boolean dfs(int v, int c) {
    if (colors[v]!=0)
      return colors[v]==c;

    colors[v] = c;
    // System.out.println(v+" "+c);
    for (int w : graph.get(v))
      if (!dfs(w, -c))
        return false;
    return true;
  }
}