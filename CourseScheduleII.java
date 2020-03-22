import java.util.*;

public class CourseScheduleII {
  boolean impossible=false;
  int WHITE=0, GREY=1, BLACK=2;
  int[] color;
  Stack<Integer> stack;
  Map<Integer, Set<Integer>> graph;
  public int[] findOrder(int numCourses, int[][] prerequisites) {
    color = new int[numCourses];
    stack = new Stack<>();
    graph = new HashMap<>();
    for (int[] edge : prerequisites) {
      int q = edge[0], p = edge[1];
      if (!graph.containsKey(p)) graph.put(p, new HashSet<>());
      graph.get(p).add(q);
    }

    for (int i=0; i<numCourses; ++i)
      if (color[i]==WHITE) dfs(i);

    int[] res;
    if (impossible) {
      res = new int[0];
    }
    else {
      res = new int[numCourses];
      for (int i=0; i<numCourses; ++i)
        res[i]=stack.pop();
    }
    return res;
  }

  public void dfs(int node) {
    if (impossible) return;

    color[node]=GREY;
    if (graph.containsKey(node))
      for (int next : graph.get(node))
        if (color[next]==WHITE) dfs(next);
        else if (color[next]==GREY) impossible=true;

    color[node]=BLACK;
    stack.push(node);
  }


  public int[] findOrderBFS(int numCourses, int[][] prerequisites) {
    int[] res = new int[numCourses], count = new int[numCourses];
    graph = new HashMap<>();
    for (int[] edge : prerequisites) {
      int q = edge[0], p = edge[1];
      if (!graph.containsKey(p)) graph.put(p, new HashSet<>());
      graph.get(p).add(q);
      count[q]++;
    }

    Queue<Integer> queue = new ArrayDeque<>();
    for (int i=0; i<numCourses; ++i)
      if (count[i]==0) queue.offer(i);

    int idx=0;
    while (!queue.isEmpty()) {
      int node = queue.poll();
      res[idx++]=node;
      if (graph.containsKey(node))
        for (int next : graph.get(node)) {
          count[next]--;
          if (count[next]==0) queue.offer(next);
        }
    }

    for (int i=0; i<numCourses; i++)
      if (count[i]!=0) return null;
    return res;
  }
}