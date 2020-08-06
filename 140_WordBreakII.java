import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

class WordBreakII {
  public List<String> wordBreak(String s, List<String> wordDict) {
    Map<Integer, Set<String>> dicts = new HashMap<>();
    for (String w : wordDict) {
      if (!dicts.containsKey(w.length()))
        dicts.put(w.length(), new HashSet<>());
      dicts.get(w.length()).add(w);
    }


    List<List<String>> memo = new ArrayList<>();
    int n = s.length();
    for (int i=0; i<n; ++i)
      memo.add(new ArrayList<>());

    for (int i=n-1; i>=0; --i) {
      for (int len : dicts.keySet()) {
        if (i+len>n) continue;
        String l = s.substring(i, i+len);
        if (dicts.get(len).contains(l)) {
          List<String> temp = memo.get(i);
          if (i+len==n)
            temp.add(l);
          else {
            l += ' ';
            for (String r : memo.get(i+len))
              temp.add(l+r);
          }
        }
      }
    }
    return memo.get(0);
  }
}