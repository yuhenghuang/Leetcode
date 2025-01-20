import java.util.Arrays;

class StoneGameIII {
  public static void main(String[] args) {
    int[] stones = new int[] {-1,-2,-3};
    StoneGameIII obj = new StoneGameIII();
    System.out.println(obj.stoneGameIII(stones));
  }
  int N;
  int[] stones, a, b;
  public String stoneGameIII(int[] stoneValue) {
    stones = stoneValue;
    N = stoneValue.length;
    a = new int[N];
    b = new int[N];
    Arrays.fill(a, Integer.MIN_VALUE);
    Arrays.fill(b, Integer.MAX_VALUE);

    int alice = dfs(0, true);
    int bob = Arrays.stream(stoneValue).sum() - alice;
    return alice==bob ? "Tie" : (alice>bob ? "Alice" : "Bob");
  }

  int dfs(int idx, boolean alice) {
    if (idx>=N) return 0;
    if (alice) {
      if (a[idx]!=Integer.MIN_VALUE)
        return a[idx];
      int res=Integer.MIN_VALUE, acc=0;
      for (int k=0; k<Math.min(N-idx, 3); ++k) {
        acc += stones[idx+k];
        res = Math.max(res, acc + dfs(idx+k+1, !alice));
      }
      a[idx] = res;
      return res;
    }
    else {
      if (b[idx]!=Integer.MAX_VALUE)
        return b[idx];
      int res = Integer.MAX_VALUE;
      for (int k=0; k<Math.min(N-idx, 3); ++k) 
        res = Math.min(res, dfs(idx+k+1, !alice));
      b[idx] = res;
      return res;
    }
  }
}