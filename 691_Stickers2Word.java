import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

class Stickers2Word {
  public int minStickers(String[] stickers, String target) {
    int len=0;
    Map<Character, Integer> dict = new HashMap<>();
    for (char c : target.toCharArray())
      if (!dict.containsKey(c))
        dict.put(c, len++);

    int[] tar = new int[len];
    for (char c : target.toCharArray())
      tar[dict.get(c)]++;

    Set<int[]> cand = new HashSet<>();
    Arrays.sort(stickers, (s1, s2) -> s2.length() - s1.length());
    for (String s : stickers) {
      int[] temp = new int[len];
      for (char c : s.toCharArray()) 
        if (dict.containsKey(c))
          temp[dict.get(c)]++;

      boolean flag = true;
      for (int i=0; i<len; ++i)
        if (temp[i]>0) {
          flag = false;
          break;
        }
      if (flag) continue;

      for (int[] pre : cand) {
        flag = true;
        for (int i=0; i<len; ++i) 
          if (pre[i]<temp[i]) {
            flag = false;
            break;
          }
        if (flag)
          break;
      }
      if (flag) continue;

      cand.add(temp);
    }

    Set<int[]> memo = new HashSet<>();
    memo.add(tar);
    int res=1;
    while (!memo.isEmpty()) {
      Set<int[]> next = new HashSet<>();
      for (int[] prior : memo) 
        for (int[] pre : cand) {
          int[] temp = prior.clone();
          for (int i=0; i<len; ++i) 
            temp[i]-=pre[i];

          boolean flag=true;
          for (int i=0; i<len; ++i)
            if (prior[i]>0 && temp[i]<prior[i]) {
              flag = false;
              break;
            }
          if (flag) continue;

          flag = true;
          for (int i=0; i<len; ++i)
            if (temp[i]>0) {
              flag = false;
              break;
            }
          if (flag) return res;
          next.add(temp);
        }
      memo = next;
      res++;
    }
    return -1;
  }
}