import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class GroupAnagram {
  public List<List<String>> groupAnagrams(String[] strs) {
    List<List<String>> res = new ArrayList<>();
    Map<String, List<String>> map = new HashMap<>();

    int[] temp = new int[26];
    for (String s: strs) {
      Arrays.fill(temp, 0);
      for (char c : s.toCharArray())
        temp[c-'a']++;
      StringBuilder sb = new StringBuilder("");
      for (int i=0; i<26; ++i) {
        sb.append('#');
        sb.append(temp[i]);
      }
      
      String ana = sb.toString();
      if (!map.containsKey(ana))
        map.put(ana, new ArrayList<>());
      map.get(ana).add(s);
    }
    res.addAll(map.values());
    return res;
  }

  public List<List<String>> groupAnagramsSort(String[] strs) {
    List<List<String>> res = new ArrayList<>();
    Map<String, List<String>> map = new HashMap<>();
    for (String s : strs) {
      char[] cs = s.toCharArray();
      Arrays.sort(cs);
      String ana = new String(cs);
      if (!map.containsKey(ana))
        map.put(ana, new ArrayList<>());
      map.get(ana).add(s);
    }
    res.addAll(map.values());
    return res;
  }
}