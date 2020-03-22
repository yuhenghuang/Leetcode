import java.util.*;

public class CourseScheduleI {
  public boolean canFinish(int numCourses, int[][] prerequisites) {
    //int n = prerequisites.length;

    int[] count = new int[numCourses];
    Map<Integer, Set<Integer>> graph = new HashMap<>();
    for (int[] edge : prerequisites) {
      int q = edge[0], p = edge[1];
      if (!graph.containsKey(p)) graph.put(p, new HashSet<>());
      graph.get(p).add(q);
      count[q]++;
    }
    
    Queue<Integer> queue = new ArrayDeque<>();
    for (int i=0; i<numCourses; i++)
      if (count[i]==0) queue.offer(i);

    while (!queue.isEmpty()) {
      int node = queue.poll();
      if (graph.containsKey(node))
        for (int next : graph.get(node)) {
          count[next]--;
          if (count[next]==0) queue.offer(next);
        }
    }

    for (int i=0; i<numCourses; i++)
      if (count[i]!=0) return false;
    return true;
  }
}