import java.util.*;

public class LetterPhoneNum {
  public static void main(String[] args) {
    LetterPhoneNum obj = new LetterPhoneNum();
    System.out.println(obj.letterCombinations("23"));
  }
  Map<Character, Set<Character>> dict;
  List<String> res;
  String nums;
  int N;
  public List<String> letterCombinations(String digits) {
    res = new ArrayList<>();
    if (digits.length()==0) return res;
    dict = new HashMap<>();
    nums=digits;
    N = digits.length();
    int[] buttons = new int[] {3,3,3,3,3,4,3,4};
    int st = 97;
    for (int i=0; i<buttons.length; i++) {
      char key = Integer.toString(i+2).charAt(0);
      dict.put(key, new HashSet<Character>());
      int cnt=buttons[i];
      while (cnt-->0) {
        dict.get(key).add((char) st++);
      }
    }
    //System.out.println(dict);
    dfs(new StringBuilder(), 0);
    return res;
  }

  private void dfs(StringBuilder str, int idx) {
    if (idx==N) {
      res.add(str.toString());
      return;
    }
    for (char c : dict.get(nums.charAt(idx))) {
      str.append(c);
      dfs(str, idx+1);
      str.deleteCharAt(idx);
    }
  }
}