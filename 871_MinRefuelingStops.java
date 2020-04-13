import java.util.Arrays;

class MinRefuelingStops {
  public int minRefuelStops(int target, int startFuel, int[][] stations) {
    int N = stations.length;
    int[] fuels = new int[N+2];
    int[] locations = new int[N+2];
    locations[N+1] = target;
    long[] base = new long[N+2];

    Arrays.fill(base, -1);
    long[] memo = base.clone();

    for (int i=1; i<=N; ++i) {
      fuels[i] = stations[i-1][1];
      locations[i] = stations[i-1][0];
    }
    memo[0] = startFuel;

    for (int i=0; i<N+1; ++i) {
      long[] next = base.clone();
      int dist = locations[i+1] - locations[i];
      for (int j=i; j>=0; j--) {
        if (memo[j]-dist<0) break;
        next[j+1] = Math.max(next[j+1], memo[j] - dist + fuels[i+1]);
        next[j] = Math.max(next[j], memo[j] - dist);
      }
      memo = next;
    }

    for (int i=0; i<=N+1; i++)
      if (memo[i]>=0)
        return i;
    return -1;
  }
}