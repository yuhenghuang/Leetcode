public class LongestMountain {
  public int longestMountain(int[] A) {
    int N = A.length;
    int i=0; int res=0;
    int st, peak;
    while (i<N-1) {
      st=i;
      while (i<N-1 && A[i]<A[i+1]) i++;
      if (i==st) {
        i++;
        continue;
      }
      peak=i;
      while (i<N-1 && A[i]>A[i+1]) i++;
      if (i==peak) {
        i++;
        continue;
      }
      res=Math.max(res, i-st+1);
    }

    return res;
  }
}