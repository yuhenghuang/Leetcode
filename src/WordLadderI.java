import java.util.*;

public class WordLadderI {
  public static void main(String[] args) {
    List<String> words = new ArrayList<>(List.of("hot","dot","dog","lot","log"));
    WordLadderI obj = new WordLadderI();
    System.out.println(obj.ladderLength("hit", "cog", words));
  }



  Queue<String> queue;
  public int ladderLength(String beginWord, String endWord, List<String> wordList) {
    TrieNode root = new TrieNode('#');
    for (String w : wordList) {
      TrieNode node = root;
      for (char c : w.toCharArray()) {
        if (!node.dict.containsKey(c))
          node.dict.put(c, new TrieNode(c));
        node = node.dict.get(c);
      }
      node.flag = true;
    }

    queue = new ArrayDeque<>();
    queue.offer(beginWord);
    int res=1;
    while (!queue.isEmpty()) {
      int N = queue.size();
      while (N-->0) {
        String node = queue.poll();
        if (node.equals(endWord)) return res;
        dfs("", root, node, 0);
      }
      res++;
    }
    return 0;
  }

  public void dfs(String w, TrieNode node, String s, int count) {
    if (s.length()==0) {
      if (node.flag && count==1) {
        queue.offer(w);
        node.flag=false;
      }
      return;
    }

    if (node.dict.containsKey(s.charAt(0))) {
      dfs(w+s.substring(0, 1), node.dict.get(s.charAt(0)), s.substring(1), count);
    }

    if (count==0)
      for (char c : node.dict.keySet())
        if (c!=s.charAt(0))
          dfs(w+c, node.dict.get(c), s.substring(1), count+1);
  }

  class TrieNode {
    char c;
    boolean flag;
    Map<Character,TrieNode> dict;
    TrieNode (char val) {
      dict = new HashMap<>();
      c = val;
      flag = false;
    }
  }
}