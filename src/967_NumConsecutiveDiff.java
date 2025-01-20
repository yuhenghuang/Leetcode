import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class NumConsecutiveDiff {
  public static void main(String[] args) {
    NumConsecutiveDiff obj = new NumConsecutiveDiff();
    int[] res = obj.numsSameConsecDiff(2, 0);
    System.out.println(Arrays.toString(res));
  }
  public int[] numsSameConsecDiff(int N, int K) {
    List<Integer> prev = new ArrayList<>();
    for (int i=1; i<10; ++i) {
      prev.add(i);
    }

    if (N==1) prev.add(0);

    while (N-->1) {
      List<Integer> next = new ArrayList<>();
      for (int s : prev) {
        int res = s % 10;
        if (res+K<=9) next.add(s*10 + res + K);
        if (K!=0 && res-K>=0) next.add(s*10 + res - K);
      }
      prev = next;
    }
    int[] ans = new int[prev.size()];
    Arrays.setAll(ans, prev::get);
    return ans;
  }
}