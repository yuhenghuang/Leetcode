import java.util.Arrays;

public class HIndex {
  public static void main(String[] args) {
    HIndex obj = new HIndex();
    int res = obj.hIndex(new int[] {5});
    System.out.println(res);
  }

  public int hIndex(int[] citations) {
    Arrays.sort(citations);
    int N=citations.length;
    for (int i=0; i<N; ++i)
      if (N-i<=citations[i])
        return N-i;
    return 0;
  }



  public int hIndex_redundant(int[] citations) {
    Arrays.sort(citations);
    int res=0, prev=0, N=citations.length;
    for (int i=0; i<N; ++i) {
      if (citations[i]>prev) {
        if (N-i>=prev) res=Math.min(citations[i], N-i); 
        prev=citations[i];
      }
    }
    return res;
  }
}