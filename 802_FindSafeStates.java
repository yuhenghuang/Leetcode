import java.util.ArrayList;
import java.util.List;

class FindSafeStates {
  int[][] graph;
  boolean[] safe, visited;
  public List<Integer> eventualSafeNodes(int[][] graph) {
    int N = graph.length;
    this.graph = graph;
    safe = new boolean[N];
    visited = new boolean[N];
    List<Integer> res = new ArrayList<>();

    for (int i=0; i<N; ++i)
      if (!visited[i])
        dfs(i);

    for (int i=0; i<N; ++i)
      if (safe[i] || graph[i].length==0)
        res.add(i);
    return res;
  }

  boolean dfs(int v) {
    if (graph[v].length==0) return true;
    else if (visited[v]) return safe[v];
    visited[v] = true;
    for (int w : graph[v]) 
      if (!dfs(w))
        return false;
    safe[v] = true;
    return true;
  }
}