import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Queue;
import java.util.Set;

class CourseScheduleIV {
  Queue<Integer> queue;
  List<List<Integer>> graph;
  List<Set<Integer>> relations;
  boolean[][] memo;
  public List<Boolean> checkIfPrerequisite(int n, int[][] prerequisites, int[][] queries) {
    graph = new ArrayList<>();
    relations = new ArrayList<>();
    for (int i=0; i<n; ++i) {
      graph.add(new ArrayList<>());
      relations.add(new HashSet<>());
    }

    // boolean[] non_start = new boolean[n];
    
    for (int[] pair : prerequisites) {
      graph.get(pair[0]).add(pair[1]);
      // non_start[pair[1]] = true;
    }

    memo = new boolean[n][n];

    // for (int i=0; i<n; ++i)
    //   if (!non_start[i])
    //     dfs(i);

    queue = new ArrayDeque<>();
    for (int i=0; i<n; ++i)
      bfs(i);

    List<Boolean> res = new ArrayList<>();
    for (int[] pair : queries)
      res.add(memo[pair[0]][pair[1]]);

    return res;
  }

  void bfs(int v) {
    queue.offer(v);
    while (!queue.isEmpty()) {
      int w = queue.poll();
      memo[v][w] = true;
      for (int e : graph.get(w))
        queue.offer(e);
    }
  }

  Set<Integer> dfs(int v) {
    Set<Integer> children = relations.get(v);

    if (children.size()>0) 
      return children;

    for (int w : graph.get(v)) {
      children.add(w);
      children.addAll(dfs(w));
    }

    for (int e : children)
      memo[v][e] = true;

    return children;
  }
}