import java.util.HashMap;
import java.util.Map;

class FrogJump {
  public static void main(String[] args) {
    FrogJump obj = new FrogJump();
    System.out.println(obj.canCross(new int[] {0,2}));
  }
  int n;
  boolean[][] memo, visited;
  Map<Integer, Integer> map;
  public boolean canCross(int[] stones) {
    n = stones.length;
    memo = new boolean[n][n];
    visited = new boolean[n][n];
    map = new HashMap<>();
    for (int i=0; i<n; ++i)
      map.put(stones[i], i);

    return dfs(stones, 0, 0);
  }

  public boolean dfs(int[] stones, int i, int k) {
    if (i<0 || k<0) return false;
    else if (i==n-1) return true;
    if (visited[i][k]) return memo[i][k];
    visited[i][k] = true;

    memo[i][k] = dfs(stones, map.getOrDefault(stones[i]+k-1, -1), k-1) ||
                 dfs(stones, map.getOrDefault(stones[i]+k, -1), k) ||
                 dfs(stones, map.getOrDefault(stones[i]+k+1, -1), k+1);
    return memo[i][k];
  }
}