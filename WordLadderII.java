import java.util.*;

public class WordLadderII {
  public static void main(String[] args) {
    List<String> words = new ArrayList<>(List.of("ted","tex","red","tax","tad","den","rex","pee"));
    WordLadderII obj = new WordLadderII();
    System.out.println(obj.findLadders("red", "tax", words));
  }

  List<List<String>> res;
  Map<String, List<String>> dict;
  Queue<TrieNode> queue;
  Deque<String> deque;
  public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
    res = new ArrayList<>();
    dict = new HashMap<>();
    int L = beginWord.length();
    for (String w : wordList)
      for (int i=0; i<L; ++i) {
        String wNew = w.substring(0, i) + '*' + w.substring(i+1);
        if (!dict.containsKey(wNew)) dict.put(wNew, new ArrayList<>());
        dict.get(wNew).add(w);
      }

    Set<String> visited = new HashSet<>();

    TrieNode root = new TrieNode(beginWord);
    root.flag = true;
    queue = new ArrayDeque<>();
    queue.offer(root);

    boolean found = false;
    TrieNode end=null;
    while (!queue.isEmpty()) {
      int N = queue.size();
      Map<String, TrieNode> temp = new HashMap<>();
      while (N-->0) {
        TrieNode node = queue.poll();
        String w = node.val;
        for (int i=0; i<L; ++i) {
          String wNew = w.substring(0, i) + '*' + w.substring(i+1);
          for (String nextVal : dict.getOrDefault(wNew, new ArrayList<>())) 
            if (!visited.contains(nextVal)) {
              TrieNode next;
              if (temp.containsKey(nextVal)) {
                next = temp.get(nextVal);
              }
              else {
                next = new TrieNode(nextVal);
                temp.put(nextVal, next);
                queue.offer(next);
              }
              next.parents.put(node.val, node);

              if (nextVal.equals(endWord))
                found=true;
            }
        }
      }
      if (found) {
        end = temp.get(endWord);
        break;
      }
      visited.addAll(temp.keySet());
    }


    if (end!=null) {
      deque = new ArrayDeque<>();
      deque.offer(endWord);
      dfs(end);
    }
    return res;
  }

  public void dfs(TrieNode node) {
    if (node.flag) {
      res.add(new ArrayList<>(deque));
      return;
    }
    for (String val : node.parents.keySet()) {
      deque.offerFirst(val);
      dfs(node.parents.get(val));
      deque.pollFirst();
    }
  }

  class TrieNode {
    Map<String, TrieNode> parents;
    String val;
    boolean flag;
    TrieNode (String s) {
      parents = new HashMap<>();
      val = s;
      flag = false;
    }
  }
}

class LessOptimalWordLadderII {
  List<List<String>> res;
  Map<String, List<String>> dict;
  Queue<TrieNode> queue;
  Stack<String> stack;
  public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
    res = new ArrayList<>();
    dict = new HashMap<>();
    int L = beginWord.length();
    for (String w : wordList)
      for (int i=0; i<L; ++i) {
        String wNew = w.substring(0, i) + '*' + w.substring(i+1);
        if (!dict.containsKey(wNew)) dict.put(wNew, new ArrayList<>());
        dict.get(wNew).add(w);
      }

    Set<String> visited = new HashSet<>();

    TrieNode root = new TrieNode(beginWord);
    queue = new ArrayDeque<>();
    queue.offer(root);

    boolean found = false;
    while (!queue.isEmpty() && !found) {
      int N = queue.size();
      Map<String, TrieNode> temp = new HashMap<>();
      while (N-->0) {
        TrieNode node = queue.poll();
        String w = node.val;
        for (int i=0; i<L; ++i) {
          String wNew = w.substring(0, i) + '*' + w.substring(i+1);
          for (String nextVal : dict.getOrDefault(wNew, new ArrayList<>())) 
            if (!visited.contains(nextVal)) {
              TrieNode next;
              if (temp.containsKey(nextVal)) {
                next = temp.get(nextVal);
              }
              else {
                next = new TrieNode(nextVal);
                temp.put(nextVal, next);
                queue.offer(next);
              }
              node.children.put(nextVal, next);

              if (nextVal.equals(endWord)) {
                found=true;
                next.flag=true;
              }
            }
        }
      }
      visited.addAll(temp.keySet());
    }

    stack = new Stack<>();
    stack.push(root.val);
    dfs(root);
    return res;
  }

  public void dfs(TrieNode node) {
    if (node.children.isEmpty()) {
      if (node.flag) res.add(new ArrayList<>(stack));
      return;
    }

    for (String val : node.children.keySet()) {
      stack.push(val);
      dfs(node.children.get(val));
      stack.pop();
    }
  }

  class TrieNode {
    Map<String, TrieNode> children;
    String val;
    boolean flag;
    TrieNode (String s) {
      children = new HashMap<>();
      val = s;
      flag = false;
    }
  }
}