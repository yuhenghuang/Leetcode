import java.util.Map.Entry;
import java.util.Arrays;
import java.util.TreeMap;

class MaxProfitJobSchedule {
  public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
    int n = startTime.length;
    if (n==0) return 0;

    int[][] comb = new int[n][3];
    for (int i=0; i<n; ++i) {
      comb[i][0] = startTime[i];
      comb[i][1] = endTime[i];
      comb[i][2] = profit[i];
    }
    Arrays.sort(comb, (a, b) -> a[1]==b[1]?a[0]-b[0]:a[1]-b[1]);

    TreeMap<Integer, Integer> tm = new TreeMap<>();
    tm.put(comb[0][1], comb[0][2]);
    for (int i=1; i<n; ++i) {
      int res = Math.max(tm.lastEntry().getValue(), comb[i][2]);
      Entry<Integer, Integer> cut = tm.floorEntry(comb[i][0]);
      if (cut!=null) 
        res = Math.max(res, cut.getValue() + comb[i][2]);
      tm.put(comb[i][1], res);
    }
    return tm.lastEntry().getValue();
  }
}