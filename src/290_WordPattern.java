import java.util.HashMap;
import java.util.Map;

class WordPattern {
  public boolean wordPattern(String pattern, String str) {
    String[] ss = str.split("\\s");
    if (ss.length!=pattern.length())
      return false;

    char c;
    String s;
    String[] char2str = new String[26];
    Map<String, Character> str2char = new HashMap<>();
    for (int i=0; i<ss.length; ++i) {
      c = pattern.charAt(i);
      s = ss[i];
      if (!str2char.containsKey(s) && char2str[c-'a']==null) {
        str2char.put(s, c);
        char2str[c-'a'] = s;
      }
      else {
        if (str2char.getOrDefault(s, '*')!=c || !s.equals(char2str[c-'a']))
          return false;
      }
    }
    return true;
  }
}