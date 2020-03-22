import java.util.*;

public class WordSearchII {
  int m, n;
  int[] row, clm;
  boolean[][] visited;
  List<String> res;
  public List<String> findWords(char[][] board, String[] words) {
    m=board.length;
    n=m==0?0:board[0].length;
    visited = new boolean[m][n];
    res = new ArrayList<>();
    TrieNode root = new TrieNode('#');
    for (String w : words) {
      TrieNode node = root;
      for (char c : w.toCharArray()) {
        if (!node.children.containsKey(c))
          node.children.put(c, new TrieNode(c));
        node = node.children.get(c);
      }
      node.w = w;
    }

    row = new int[] {1,-1,0,0};
    clm = new int[] {0,0,1,-1};
    for (int i=0; i<m; ++i)
      for (int j=0; j<n; ++j)
        dfs(root, board, i, j);
    return res;
  }

  private void dfs(TrieNode node, char[][] board, int i, int j) {
    if (node.w.length()>0) {
      res.add(node.w);
      node.w="";
    }
    if (i<0 || j<0 || i>=m || j>=n || visited[i][j] || !node.children.containsKey(board[i][j])) return;

    TrieNode next = node.children.get(board[i][j]);
    visited[i][j]=true;
    for (int k=0; k<4; ++k)
      dfs(next, board, i+row[k], j+clm[k]);
    visited[i][j]=false;
  }


  class TrieNode {
    char c;
    Map<Character, TrieNode> children;
    String w;
    TrieNode(char ch) {
      c = ch;
      w = "";
      children = new HashMap<>();
    }
  }
}