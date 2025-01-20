public class CompareVersion {
  public static void main(String[] args) {
    CompareVersion obj = new CompareVersion();
    System.out.println(obj.compareVersion("0.1", "1.1"));
  }
  public int compareVersion(String version1, String version2) {
    int[] v1=process(version1), v2=process(version2);
    int n1=v1.length, n2=v2.length, n=Math.max(n1, n2);

    int rev1, rev2;
    for (int i=0; i<n; ++i) {
      if (i>=n1) rev1=0;
      else rev1=v1[i];
      if (i>=n2) rev2=0;
      else rev2=v2[i];
      if (rev1>rev2) {
        return 1;
      }
      else if (rev1<rev2) {
        return -1;
      }
    }
    return 0;
  }

  private int[] process(String s) {
    String[] verS = s.split("\\.");
    int[] res = new int[verS.length];
    for (int i=0; i<verS.length; i++) {
      res[i]=Integer.valueOf(verS[i]);
    }
    return res;
  }
}