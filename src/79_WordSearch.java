class WordSearch {
  public static void main(String[] args) {
    WordSearch obj = new WordSearch();
    char[][] board = new char[][] {
      {'A','B','C','E'},
      {'S','F','C','S'},
      {'A','D','E','E'}
    };

    System.out.println(obj.exist(board, "ABCCED"));
    System.out.println(obj.exist(board, "SEE"));
    System.out.println(obj.exist(board, "ABCB"));
  }
  int m, n;
  int[] dir_row, dir_clm;
  boolean[][] seen;
  public boolean exist(char[][] board, String word) {
    m = board.length;
    n = m==0? 0 : board[0].length;
    seen = new boolean[m][n];

    dir_row = new int[] {1,-1,0,0};
    dir_clm = new int[] {0,0,1,-1};

    for (int i=0; i<m; ++i)
      for (int j=0; j<n; ++j)
        if (dfs(i, j, 0, board, word))
          return true;

    return false;
  }

  boolean dfs(int i, int j, int idx, char[][] board, String word) {
    if (idx==word.length())
      return true;

    if (i<0 || i>=m || j<0 || j>=n || seen[i][j] || board[i][j]!=word.charAt(idx))
      return false;

    seen[i][j] = true;

    boolean flag = false;
    for (int k=0; k<4; ++k) {
      flag = dfs(i+dir_row[k], j+dir_clm[k], idx+1, board, word);
      if (flag) break;
    }

    seen[i][j] = false;
    return flag;
  }
}