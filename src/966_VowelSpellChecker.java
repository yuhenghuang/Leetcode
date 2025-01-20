import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class VowelSpellChecker {
  public static void main(String[] args) {
    VowelSpellChecker obj = new VowelSpellChecker();
    String[] wordlist = {"KiTe","kite","hare","Hare"};
    String[] queries = {"kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"};
    String[] res = obj.spellchecker(wordlist, queries);
    System.out.println(Arrays.toString(res));
  }
  String temp;
  StringBuilder sb;
  List<Character> vowels = new ArrayList<>(List.of('A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'));
  public String[] spellchecker(String[] wordlist, String[] queries) {

    TrieNode root = new TrieNode();
    int n = queries.length;
    for (String s : wordlist) {
      TrieNode node = root;
      for (char c : s.toCharArray())
        node = node.findAndAdd(c);
      node.flag = true;
    }

    sb = new StringBuilder("");
    String[] res = new String[n];
    for (int i=0; i<n; ++i) {
      sb.delete(0, sb.length());
      res[i] = dfs(root, 0, queries[i]) ? temp : "";
    }

    return res;
  }

  boolean dfs(TrieNode node, int idx, String s) {
    if (idx==s.length()) {
      if (node.flag) {
        temp = sb.toString();
        return true;
      }
      return false;
    }
    char c = s.charAt(idx);
    TrieNode next = node.find(c);
    if (next!=null) {
      sb.append(c);
      if (dfs(next, idx+1, s)) return true;
      sb.deleteCharAt(sb.length()-1);
    }

    char d = c>'Z' ? (char)(c-32) : (char)(c+32);
    next = node.find(d);
    if (next!=null) {
      sb.append(d);
      if (dfs(next, idx+1, s)) return true;
      sb.deleteCharAt(sb.length()-1);
    }

    if (vowels.contains(c))
      for (char e : vowels)
        if (e!=c) {
          next = node.find(e);
          if (next!=null) {
            sb.append(e);
            if (dfs(next, idx+1, s)) return true;
            sb.deleteCharAt(sb.length()-1);
          }
        }

    return false;
  }

  class TrieNode {
    TrieNode[] dict;
    boolean flag;
    TrieNode() {
      dict = new TrieNode[58];
      flag = false;
    }

    TrieNode find(char c) {
      return dict[c-'A'];
    }

    TrieNode findAndAdd(char c) {
      if (dict[c-'A']==null)
        dict[c-'A'] = new TrieNode();
      return dict[c-'A'];
    }
  }
}