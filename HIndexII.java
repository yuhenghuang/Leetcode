public class HIndexII {
  public static void main(String[] args) {
    HIndexII obj = new HIndexII();
    int res = obj.hIndex(new int[] {0});
    System.out.println(res);
  }
  public int hIndex(int[] citations) {
    int l=0, r=citations.length, N=r;
    while (l<r) {
      int m=(l+r)/2;
      if (citations[m]>=N-m) r=m;
      else l=m+1;
    }
    return N-r;
  }
}