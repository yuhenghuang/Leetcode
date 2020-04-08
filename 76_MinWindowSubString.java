import java.util.HashMap;
import java.util.Map;

class MinWindowSubString {
  public static void main(String[] args) {
    MinWindowSubString obj = new MinWindowSubString();
    System.out.println(obj.minWindow("bdab", "ab"));
  }
  public String minWindow(String s, String t) {
    if (t==null || t.length()==0) return "";
    Map<Character, Integer> map = new HashMap<>();
    for (char c : t.toCharArray())
      map.put(c, map.getOrDefault(c, 0)+1);

    int n=s.length(), l=0, r=0;
    String res = null;
    while (l<n) {
      while (r<n && !containAll(map)) {
        updateMap(map, s.charAt(r++), -1);
      }

      if (!containAll(map))
        break;

      while (l<r && containAll(map)) {
        updateMap(map, s.charAt(l++), 1);
      }

      if (res==null || res.length()>(r-l))
        res = s.substring(l-1, r);

      if (r<n)
        updateMap(map, s.charAt(r++), -1);
    }
    return res==null?"":res;
  }

  private void updateMap(Map<Character, Integer> map, char c, int sign) {
    if (map.containsKey(c))
      map.put(c, map.get(c) + sign);
  }

  private boolean containAll(Map<Character, Integer> map) {
    for (int cnt : map.values())
      if (cnt>0)
        return false;
    return true;
  }
}