import java.util.ArrayList;
import java.util.List;

class FindAllAnagramsInString {
  public static void main(String[] args) {
    FindAllAnagramsInString obj = new FindAllAnagramsInString();
    System.out.println(obj.findAnagrams("cba", "abc"));
  }
  public List<Integer> findAnagrams(String s, String p) {
    List<Integer> res = new ArrayList<>();
    int[] ans = new int[26];
    int[] cur = new int[26];
    int size_s = s.length(), size_p = p.length();
    if (size_s<size_p) return res;

    for (int i=0; i<size_p; ++i) {
      ++ans[p.charAt(i)-'a'];
      ++cur[s.charAt(i)-'a'];
    }

    for (int i=-1; i<size_s-size_p; ++i) {
      if (i>-1) {
        --cur[s.charAt(i)-'a'];
        ++cur[s.charAt(i+size_p)-'a'];
      }
      boolean flag = true;
      for (int j=0; j<26; ++j)
        if (ans[j]!=cur[j]) {
          flag = false;
          break;
        }
      if (flag) res.add(i+1);
    }
    return res;
  }
}