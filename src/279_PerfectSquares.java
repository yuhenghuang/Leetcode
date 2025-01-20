import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

class PerfectSquares {
  public static void main(String[] args) {
    PerfectSquares obj = new PerfectSquares();
    System.out.println(obj.numSquares(1));
  }
  public int numSquares(int n) {
    if (n==0) return 0;
    List<Integer> bricks = new ArrayList<>();
    for (int i=1; i*i<=n; ++i)
      bricks.add(i*i);

    boolean[] seen = new boolean[n+1];
    Queue<Integer> queue = new ArrayDeque<>();
    queue.offer(0);

    int res=1;
    while (!queue.isEmpty()) {
      int N = queue.size();
      while (N-->0) {
        int prev = queue.poll();
        for (int brick : bricks) {
          int next = prev+brick;
          if (next>n || seen[next]) continue;
          if (next==n) return res;
          seen[next] = true;
          queue.offer(next);
        }
      }
      ++res;
    }
    return res;
  }
}