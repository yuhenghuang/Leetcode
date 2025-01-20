import java.util.*;

public class GuessTheWord {

  StringBuilder sb;
  List<String> ls1, ls2;
  public void findSecretWord(String[] wordlist, Master master) {
    ls1 = new ArrayList<>();
    TrieNode root = new TrieNode('#');
    for (String s : wordlist) {
      ls1.add(s);
      TrieNode node = root;
      for (char c : s.toCharArray()) {
        if (!node.dict.containsKey(c))
          node.dict.put(c, new TrieNode(c));
        node = node.dict.get(c);
      }
    }

    sb = new StringBuilder();

    int cnt=-1;
    while (!ls1.isEmpty() && cnt++<10) {
      ls2 = new ArrayList<>();
      String t = ls1.get(0);
      int disc = 6 - master.guess(t);
      dfs(root, t, 0, disc, cnt);
      ls1 = ls2;
    }
  }

  private void dfs(TrieNode node, String target, int idx, int disc, int layer) {
    if (idx+disc>6 || disc<0) return;
    else if (idx==6 && disc==0 && node.layer==layer) {
      node.layer++;
      ls2.add(sb.toString());
      return;
    }

    for (char c : node.dict.keySet()) {
      sb.append(c);
      if (target.charAt(idx)==c) 
        dfs(node.dict.get(c), target, idx+1, disc, layer);
      else
        dfs(node.dict.get(c), target, idx+1, disc-1, layer);
      sb.deleteCharAt(sb.length()-1);
    }
  }

  class TrieNode {
    Map<Character, TrieNode> dict;
    char val;
    int layer;
    TrieNode(char c) {
      val = c;
      layer = 0;
      dict = new HashMap<>();
    }
  }


  class Master {
    public int guess(String s) {
      return 0;
    }
  }
}