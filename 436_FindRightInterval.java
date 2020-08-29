import java.util.Arrays;

class FindRightInterval {
  public int[] findRightInterval(int[][] intervals) {
    int n = intervals.length;

    int[][] memo = new int[n][2];
    for (int i=0; i<n; ++i) {
      memo[i][0] = intervals[i][0];
      memo[i][1] = i;
    }

    Arrays.sort(memo, (int[] a, int[] b) -> { return a[0] - b[0];});

    int[] res = new int[n];
    for (int i=0; i<n; ++i) 
      res[i] = binarySearch(memo, intervals[i][1]);
    return res;
  }

  int binarySearch(int[][] memo, int target) {
    int l=0, r=memo.length, m;
    while (l<r) {
      m = l + (r-l)/2;
      if (memo[m][0] > target)
        r = m;
      else if (memo[m][0] == target)
        return memo[m][1];
      else
        l = m+1;
    }
    return l==memo.length ? -1 : memo[l][1];
  }
}