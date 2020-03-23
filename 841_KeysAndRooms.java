import java.util.ArrayDeque;
import java.util.List;
import java.util.Queue;

class KeysAndRooms {
  public boolean canVisitAllRooms(List<List<Integer>> rooms) {
    boolean[] visited = new boolean[rooms.size()];
    Queue<Integer> queue = new ArrayDeque<>();
    queue.offer(0);
    while(!queue.isEmpty()) {
      int v = queue.poll();
      if (visited[v]) continue;
      visited[v]=true;
      for (int w : rooms.get(v)) {
        queue.offer(w);
      }
    }

    for (boolean b : visited)
      if (!b) return false;
    return true;
  }
}