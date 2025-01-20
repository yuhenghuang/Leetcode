public class MinDominoEqualRow {
  public int minDominoRotations(int[] A, int[] B) {
    n=A.length;
    if (n==0) return 0;
    int ans=greedy(A, B, A[0]);
    ans=Math.min(greedy(A, B, B[0]), ans);
    return ans==Integer.MAX_VALUE?-1:ans;
  }

  public int greedy(int[] A, int[] B, int val) {
    int a=0, b=0;
    for (int i=0; i<n; i++) {
      if (A[i]!=val && B[i]!=val) return Integer.MAX_VALUE;
      else if (A[i]!=val) a++;
      else if (B[i]!=val) b++;
    }
    return Math.min(a, b);
  }



  int res, n;
  public int minDominoRotationsDfs(int[] A, int[] B) {
    n=A.length;
    if (n==0) return 0;
    int ans=Integer.MAX_VALUE;
    res=0;
    if (dfs(A, B, A[0], 0))
      ans=Math.min(ans, res);
    res=0;
    if (dfs(B, A, B[0], 0))
      ans=Math.min(ans, res);
    res=0;
    if (dfs(A, B, B[0], 0))
      ans=Math.min(ans, res);
    res=0;
    if (dfs(B, A, A[0], 0))
      ans=Math.min(ans, res);
    return ans==Integer.MAX_VALUE?-1:ans;
  }

  public boolean dfs(int[] A, int[] B, int base, int idx) {
    if (idx>=n) return true;
    else if (A[idx]==base && dfs(A, B, base, idx+1)) return true;
    else if (B[idx]==base && dfs(A, B, base, idx+1)) {
      res++;
      return true;
    }
    else return false;
  }
}