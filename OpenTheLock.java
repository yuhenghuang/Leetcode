import java.util.*;

public class OpenTheLock {
  public static void main(String[] args) {
    OpenTheLock obj = new OpenTheLock();
    String[] deadends = new String[] {"0000"};
    System.out.println(obj.openLock(deadends, "8888"));
  }

  public int openLock(String[] deadends, String target) {
    Set<String> visited = new HashSet<>();
    for (String s : deadends)
      visited.add(s);

    Queue<String> queue = new ArrayDeque<>();
    queue.offer("0000");

    int res=1;
    //char[] digits = "0123456789".toCharArray();
    while (!queue.isEmpty()) {
      int N = queue.size();
      while (N-->0) {
        String prev = queue.poll();
        if (visited.contains(prev)) continue;
        visited.add(prev);
        for (int i=0; i<4; ++i)
          for (int j=1; j<15;j+=8) {
            String next = prev.substring(0, i) + String.valueOf((Character.getNumericValue(prev.charAt(i))+j)%10) + prev.substring(i+1, 4);
            queue.offer(next);
            if (next.equals(target)) return res;
          }
      }
      res++;
    }
    return -1;
  }
}