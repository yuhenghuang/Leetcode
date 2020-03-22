import java.util.Map;
import java.util.HashMap;

public class MagicDictionary {
  /** Initialize your data structure here. */
  TrieNode root;
  public MagicDictionary() {
    root = new TrieNode('#');
  }
  
  /** Build a dictionary through a list of words */
  public void buildDict(String[] dict) {
    for (String s : dict)
      addTrie(s, root);
  }

  public void addTrie(String s, TrieNode root) {
    TrieNode node = root;
    for (int i=0; i<s.length(); ++i) {
      char c = s.charAt(i);
      if (!node.dict.containsKey(c))
        node.dict.put(c, new TrieNode(c));
      node = node.dict.get(c);
    }
    node.leaf=true;
  }
  
  /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
  public boolean search(String word) {
    return magicsearch(root, word, 0);
  }

  public boolean magicsearch(TrieNode node, String w, int cnt) {
    if (cnt>1) return false;
    if (w.length()==0) 
      if (node.leaf && cnt==1) return true;
      else return false;

    if (node.dict.containsKey(w.charAt(0))) 
      if (magicsearch(node.dict.get(w.charAt(0)), w.substring(1), cnt))
        return true;
        
    for (char c : node.dict.keySet()) 
      if (c!= w.charAt(0) && magicsearch(node.dict.get(c), w.substring(1), cnt+1))
        return true;
    return false;
  }

  class TrieNode {
    char ch;
    boolean leaf;
    Map<Character, TrieNode> dict;
    TrieNode(char c) {
      ch = c;
      leaf = false;
      dict = new HashMap<>();
    }
  }
}