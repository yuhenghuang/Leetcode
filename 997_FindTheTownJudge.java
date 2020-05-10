class FindTheTownJudge {
  public int findJudge(int N, int[][] trust) {
    int[] c1 = new int[N+1], c2 = new int[N+1];
    for (int[] p : trust) {
      ++c1[p[0]];
      ++c2[p[1]];
    }

    for (int i=1; i<=N; ++i)
      if (c2[i]==N-1 && c1[i]==0)
        return i;
    return -1;
  }
}