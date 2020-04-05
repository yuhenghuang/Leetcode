import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Stack;

class SmallestSufficientTeam {
  int m, n, target;
  int[] pp;
  Stack<Integer> stack;
  List<Integer> res;
  public int[] smallestSufficientTeam(String[] req_skills, List<List<String>> people) {
    m=people.size();
    n=req_skills.length;
    target=0;
    Map<String, Integer> map = new HashMap<>();
    for (int i=0; i<n; ++i) {
      target += 1 << i;
      map.put(req_skills[i], i);
    }

    pp = new int[m];
    for (int i=0; i<m; ++i) 
      for (String s : people.get(i))
        pp[i] += 1 << map.get(s);

    stack = new Stack<>();
    res = new ArrayList<>();
    dfs(0);
    int[] ans = new int[res.size()];
    Arrays.setAll(ans, res::get);
    return ans;
  }

  private void dfs(int curSkill){
    if (curSkill==target) {
      if (res.isEmpty() || res.size()>stack.size()) {
        res.clear();
        res.addAll(stack);
      }
      return;
    }
    else if (!res.isEmpty() && res.size()<=stack.size())
      return;

    int rem = 0;
    while (((curSkill >> rem) & 1) == 1)
      rem++;
    for (int i=0; i<m; ++i) {
      if (pp[i]==0) continue;
      if (((pp[i] >> rem) & 1) == 1) {
        stack.push(i);
        dfs(curSkill | pp[i]);
        stack.pop();
      }
    }
  }



  public int[] smallestSufficientTeamBFS(String[] req_skills, List<List<String>> people) {
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
        int rem = 0;
        while (((k >> rem) & 1) == 1)
          rem++;
        List<Integer> temp_list = memo.get(k);
        for (int i=0; i<m; ++i) 
          if (pp[i]!=0 && ((pp[i] >> rem) & 1)==1) {
            int temp = k | pp[i];
            if (!memo.containsKey(temp) && !next.containsKey(temp)) {
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