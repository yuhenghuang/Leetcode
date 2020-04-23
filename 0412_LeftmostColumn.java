import java.util.*;

class LeftmostColumn {
  public int leftMostColumnWithOne(BinaryMatrix binaryMatrix) {
    List<Integer> dim = binaryMatrix.dimensions();
    int m = dim.get(0), n = dim.get(1); // row and column length;
    int res = Integer.MAX_VALUE;
    for (int i=0; i<m; i++)
      res = Math.min(res, binarySearch(i, n, binaryMatrix));

    return res==Integer.MAX_VALUE?-1:res;
  }

  int binarySearch(int i, int n, BinaryMatrix binaryMatrix) {
    int l=0, r=n;
    while (l<r) {
      int m = l + (r-l) / 2;
      if (binaryMatrix.get(i, m)==0)
        l = m+1;
      else
        r = m;
    }
    if (r==n || binaryMatrix.get(i, r)==0)
      return Integer.MAX_VALUE;
    else return r;
  }

  class BinaryMatrix {
    public int get(int x, int y) { return -1; }
    public List<Integer> dimensions() { return null; }
  };
  
}