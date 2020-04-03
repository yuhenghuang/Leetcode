import java.util.TreeMap;
import java.util.Map.Entry;

class OddEvenJump {
  public static void main(String[] args) {
    OddEvenJump obj = new OddEvenJump();
    int[] nums = new int[] {5,1,3,4,2};
    System.out.println(obj.oddEvenJumps(nums));
  }
  public int oddEvenJumps(int[] A) {
    int n = A.length;
    if (n==0) return 0;

    boolean[][] memo = new boolean[n][2];
    memo[n-1][0] = true;
    memo[n-1][1] = true;

    TreeMap<Integer, Integer> treemap = new TreeMap<>();
    treemap.put(A[n-1], n-1);
    for (int i=n-2; i>=0; --i) {
      Entry<Integer, Integer> next = treemap.ceilingEntry(A[i]);
      if (next!=null) memo[i][0] = memo[next.getValue()][1];
      next = treemap.floorEntry(A[i]);
      if (next!=null) memo[i][1] = memo[next.getValue()][0];
      treemap.put(A[i], i);
    }

    int res = 0;
    for (int i=0; i<n; ++i)
      if (memo[i][0])
        res++;
    return res;
  }
}