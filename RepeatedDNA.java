import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;

public class RepeatedDNA {
  public static void main(String[] args) {
    RepeatedDNA obj = new RepeatedDNA();
    String s ="AAAAAAAAAAAAA";
    System.out.println(obj.findRepeatedDnaSequences(s));
  }
  public List<String> findRepeatedDnaSequences(String s) {
    Map<Integer, Boolean> seen = new HashMap<>();
    List<String> res = new ArrayList<>();

    Map<Character, Integer> dict = Map.of('A', 0,
                                          'C', 1,
                                          'G', 2,
                                          'T', 3);
    int cur=0, idx=0, base=(1<<20)-1;
    while (idx<s.length()) {
      if (idx<10) {
        cur=cur<<2 | dict.get(s.charAt(idx));
      }
      else {
        cur=((cur<<2)&base) | dict.get(s.charAt(idx));
      }
      if (idx>=9) {
        if (seen.containsKey(cur)) {
          if (!seen.get(cur)) {
            res.add(s.substring(idx-9, idx+1));
            seen.put(cur, true);
          }
        }
        else {
          seen.put(cur, false);
        }
      }
      idx++;
    }
    System.out.println(seen);
    return res;
  }
}