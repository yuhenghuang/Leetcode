import java.util.Set;
import java.util.HashSet;
import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;
import java.util.Stack;

public class RedundantDirectConnection {
  public int[] findRedundantDirectedConnection(int[][] edges) {
    int N = edges.length;
    Map<Integer, Integer> parent = new HashMap<>();
    List<int[]> candidates = new ArrayList<>();
    for (int[] edge : edges) {
      if (parent.containsKey(edge[1])) {
        candidates.add(new int[]{parent.get(edge[1]), edge[1]});
        candidates.add(edge);
      }
      else parent.put(edge[1], edge[0]);
    }

    int root=orbit(1, parent).node;
    if (candidates.isEmpty()) {
      Set<Integer> cycle = orbit(root, parent).seen;
      for (int i=N-1; i>=0; --i)
        if (cycle.contains(edges[i][0]) && cycle.contains(edges[i][1]))
          return edges[i];
    }

    Map<Integer, Set<Integer>> children = new HashMap<>();
    for (int c : parent.keySet()) {
      int p = parent.get(c);
      if (!children.containsKey(p))
        children.put(p, new HashSet<>());
      children.get(p).add(c);
    }

    boolean[] seen = new boolean[N+1];
    seen[0]=true;
    Stack<Integer> stack = new Stack<>();
    stack.push(root);
    while(!stack.isEmpty()) {
      int node = stack.pop();
      seen[node]=true;
      for (int c : children.get(node))
        if (!seen[c])
          stack.push(c);
    }

    for (boolean b : seen)
      if (!b) return candidates.get(0);
    return candidates.get(1);
  }

  public OrbitResults orbit(int node, Map<Integer, Integer> parent) {
    Set<Integer> seen = new HashSet<>();
    while (parent.get(node)!=node && !seen.contains(node)) {
      seen.add(node);
      node=parent.get(node);
    }
    return new OrbitResults(node, seen);
  }

  class OrbitResults {
    int node;
    Set<Integer> seen;
    OrbitResults(int n, Set<Integer> s) {
      node = n;
      seen = s;
    }
  }
}