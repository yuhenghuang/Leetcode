class JumpGameIII {
  boolean[] seen;
  public boolean canReach(int[] arr, int start) {
    seen = new boolean[arr.length];
    return dfs(start, arr);
  }

  boolean dfs(int idx, int[] arr) {
    if (idx<0 || idx>=arr.length || seen[idx])
      return false;
    seen[idx] = true;
    return arr[idx]==0 ? true : (dfs(idx+arr[idx], arr) || dfs(idx-arr[idx], arr));
  }
}