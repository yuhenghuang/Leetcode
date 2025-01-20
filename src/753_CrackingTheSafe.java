import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

class CrackingTheSafe {
  public static void main(String[] args) {
    CrackingTheSafe obj = new CrackingTheSafe();
    System.out.println(obj.crackSafe(4, 4));
  }
  int k, N, mod;
  boolean[] visited;
  Stack<Integer> stack;
  List<Integer> res;
  public String crackSafe(int n, int k) {
    // TLE
    this.k = k;
    N = (int) Math.pow(k, n) + n-1;
    mod = (int) Math.pow(10, n-1);
    visited = new boolean[mod*10];
    stack = new Stack<>();
    stack.push(0);
    dfs();
    StringBuilder sb = new StringBuilder();
    for (int i : res)
      sb.append(String.valueOf(i % 10));
    return sb.toString();
  }

  public void dfs() {
    if (stack.size()==N) {
      res = new ArrayList<>(stack);
      return;
    }
    int prev = (stack.peek() % mod) * 10;
    for (int i=0; i<k; ++i) {
      int next = prev+i;
      if (visited[next]) continue;
      visited[next] = true;
      stack.push(next);
      dfs();
      stack.pop();
      visited[next] = false;
    }
  }

}