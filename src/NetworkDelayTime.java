import java.util.Map;
import java.util.HashMap;
import java.util.Set;
import java.util.HashSet;
import java.util.Queue;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.PriorityQueue;
//import java.awt.Point;

public class NetworkDelayTime {
  public static void main(String[] args) {
    NetworkDelayTime obj = new NetworkDelayTime();
    int[][] times = new int[][] {{2,1,1}};
    int out=obj.networkDelayTime(times, 2, 2);
    System.out.println(out);
  }

  public int networkDelayTime(int[][] times, int N, int K) {
    timelog = new int[N+1][N+1];
    network = new HashMap<>();
    for (int[] time : times) {
      timelog[time[0]][time[1]] = time[2];
      if (!network.containsKey(time[0]))
        network.put(time[0], new HashSet<>());
      network.get(time[0]).add(time[1]);
    }

    PriorityQueue<int[]> heap = new PriorityQueue<>(
      (info1, info2) -> info1[1] - info2[1]);
    heap.offer(new int[]{K, 0});

    Map<Integer, Integer> dist = new HashMap<>();
    while (!heap.isEmpty()) {
      int[] info = heap.poll();
      int node=info[0], d = info[1];
      
      if (dist.containsKey(node)) 
        continue;
      
      dist.put(node, d);
      if (network.containsKey(node))
        for (int next : network.get(node)) 
          if (!dist.containsKey(next))
            heap.offer(new int[]{next, d+times[node][next]});
    }

    if (dist.size()<N) return -1;
    int res=0;
    for (int d: dist.values())
      if (d>res)
        res=d;
    return res;
  }





  boolean[] seen, visited;
  int[] dp;
  int[][] timelog;
  Map<Integer, Set<Integer>> network;
  public int networkDelayTime_bfs(int[][] times, int N, int K) {
    timelog = new int[N+1][N+1];
    network = new HashMap<>();
    for (int[] time : times) {
      timelog[time[0]][time[1]] = time[2];
      if (!network.containsKey(time[0]))
        network.put(time[0], new HashSet<>());
      network.get(time[0]).add(time[1]);
    }

    dp = new int[N+1];
    Arrays.fill(dp, Integer.MAX_VALUE);
    dp[K]=0;
    //seen = new boolean[N+1];
    //seen[0] = true;
    Queue<Pair> queue = new ArrayDeque<>();
    if (network.containsKey(K))
      queue.add(new Pair(K, 0));

    while(!queue.isEmpty()) {
      Pair p = queue.poll();
      int node = p.node;
      int dist = p.dist;
      for (int next : network.get(node)) {
        int temp=dist+timelog[node][next];
        if (temp<dp[next]) {
          dp[next]=temp;
          if (network.containsKey(next))
            queue.add(new Pair(next, temp));
        }
      }
    }

    int res=0;
    for (int i=1; i<=N; ++i) 
      if (dp[i]>res)
        res=dp[i];

    return res==Integer.MAX_VALUE?-1:res;

    // visited = new boolean[N+1];
    // int res=dfs(K);

    // for (boolean b : seen)
    //   if (!b) return -1;
    // return res;
  }

  class Pair{
    int node;
    int dist;
    Pair(int n, int d){
      node = n;
      dist = d;
    }
  }

  public int dfs(int st) {
    seen[st]=true;
    if (!network.containsKey(st)) return 0;

    int res=0;
    visited[st]=true;
    for (int ed : network.get(st))
      if (!visited[ed])
        res=Math.max(res, timelog[st][ed]+dfs(ed));
    visited[st]=false;
    return res;
  }
}