import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class SmallestSufficientTeam {
  public int[] smallestSufficientTeam(String[] req_skills, List<List<String>> people) {
    int m=people.size(), n=req_skills.length, target=0;
    Map<String, Integer> map = new HashMap<>();
    for (int i=0; i<n; ++i) {
      target += 1 << i;
      map.put(req_skills[i], i);
    }

    int[] pp = new int[m];
    for (int i=0; i<m; ++i) 
      for (String s : people.get(i))
        pp[i] += 1 << map.get(s);

    Map<Integer, List<Integer>> memo = new HashMap<>();
    memo.put(0, new ArrayList<>());
    while (true) {
      Map<Integer, List<Integer>> next = new HashMap<>();
      for (int k : memo.keySet()) {
        List<Integer> temp_list = memo.get(k);
        for (int i=0; i<m; ++i) 
          if (!temp_list.contains(i)) {
            int temp = k | pp[i];
            if (temp>k && !memo.containsKey(temp) && !next.containsKey(temp)) {
              List<Integer> res = new ArrayList<>(temp_list);
              res.add(i);
              if (temp==target) {
                int[] ans = new int[res.size()];
                Arrays.setAll(ans, res::get);
                return ans;
              }
              next.put(temp, res);
            }
          }
      }
      memo = next;
    }
  }
}