import java.util.ArrayList;
import java.util.List;

class IntervalListIntersections {
  public int[][] intervalIntersection(int[][] A, int[][] B) {
    int m = A.length, n = B.length;
    int i = 0, j = 0;
    List<int[]> res = new ArrayList<>();
    while (i<m && j<n) {
      if (A[i][0] > B[j][1])
        ++j;
      else if (A[i][1] < B[j][0])
        ++i;
      else {
        res.add(new int[] {Math.min(A[i][0], B[j][0]), Math.min(A[i][1], B[j][1])});
        if (A[i][1]<B[j][1])
          ++i;
        else if (A[i][1]>B[j][1])
          ++j;
        else {
          ++i;
          ++j;
        }
      }
    }
    return res.toArray(int[][]::new);
  }
}