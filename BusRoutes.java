import java.util.Map;
import java.util.Queue;
import java.util.HashMap;
import java.util.Set;
import java.util.HashSet;
import java.util.List;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.awt.Point;


public class BusRoutes {
  public static void main(String[] args) {
    BusRoutes obj = new BusRoutes();
    int res;
    res=obj.numBusesToDestination(new int[][] {{1,2,7}, {3,6,7}}, 1, 6);
    System.out.println(res);
  }
  public int numBusesToDestination(int[][] routes, int S, int T) {
    if (S==T) return 0;
    int N = routes.length;

    List<List<Integer>> graph = new ArrayList<>();
    for (int i=0; i<N; ++i) {
      graph.add(new ArrayList<>());
      Arrays.sort(routes[i]);
    }

    Set<Integer> seen = new HashSet<>();
    Set<Integer> target = new HashSet<>();
    Queue<Point> queue = new ArrayDeque<>();

    for (int i=0; i<N; ++i) {
      for (int j=i+1; j<N; ++j) {
        if (intersect(routes[i], routes[j])) {
          graph.get(i).add(j);
          graph.get(j).add(i);
        }
      }
    }

    for (int i=0; i<N; ++i) {
      if (Arrays.binarySearch(routes[i], S)>=0) {
        seen.add(i);
        queue.offer(new Point(i, 0));
      }
      if (Arrays.binarySearch(routes[i], T)>=0) {
        target.add(i);
      }
    }

    int node, depth;
    while (!queue.isEmpty()) {
      Point info = queue.poll();
      node = info.x; depth = info.y;
      if (target.contains(node)) return depth+1;
      for (int stop : graph.get(node)) {
        if (!seen.contains(stop)) {
          seen.add(stop);
          queue.offer(new Point(stop, depth+1));
        }
      }
    }
    return -1;
  }

  public boolean intersect(int[] A, int[] B) {
    int i=0; int j=0;
    while (i<A.length && j<B.length) {
      if (A[i]==B[j]) return true;
      if (A[i]<B[j]) i++; else j++;
    }
    return false;
  }
}


class LessEfficientAns {
  public int numBusesToDestination(int[][] routes, int S, int T) {
    if (S==T) return 0;

    Map<Integer, Set<Integer>> graph = new HashMap<>();
    Set<Integer> route;
    for (int i=0; i<routes.length; ++i) {
      route = new HashSet<Integer>();
      for (int stop : routes[i]) route.add(stop);
      for (int stop : routes[i]) {
        route.remove(stop);
        if (graph.containsKey(stop)) {
          graph.get(stop).addAll(route);
        }
        else {
          graph.put(stop, new HashSet<Integer>(route));
        }
        route.add(stop);
      }
    }

    int buses=1;

    Set<Integer> temp;
    Set<Integer> log = new HashSet<>();
    Set<Integer> start = new HashSet<>();
    start.add(S);
    log.add(S);
    while (!start.isEmpty()) {
      temp = new HashSet<>();

      for (int stop_now: start) {
        if(!graph.containsKey(stop_now)) continue;
        for (int stop_next: graph.get(stop_now)) {
          if (!log.contains(stop_next)) {
            if (stop_next==T) return buses;
            log.add(stop_next);
            temp.add(stop_next);
          }
        }
      }

      ++buses;
      start=temp;
    }

    return -1;
  }
}