class ValidParenthesisString {
  boolean[][] memo;
  public boolean checkValidString(String s) {
    this.s = s;
    N = s.length();
    if (N==0) return true;
    memo = new boolean[N+1][N*2];
    dp(0, 0);
    return memo[N][0];
  }

  public void dp(int i, int acc) {
    if (acc<0 || memo[i][acc]) return;
    memo[i][acc] = true;
    if (i==N) return;

    char c = s.charAt(i);
    if (c=='(' || c=='*')
      dp(i+1, acc+1);
    if (c==')' || c=='*')
      dp(i+1, acc-1);
    if (c=='*')
      dp(i+1, acc);
  }

  int N;
  String s;
  public boolean checkValidStringDFS(String s) {
    N = s.length();
    this.s = s;
    return dfs(0, 0);
  }

  boolean dfs(int i, int acc) {
    if (acc<0) return false;
    if (i==N) 
      if (acc==0) return true;
      else return false;
    
    boolean b=false;
    if (s.charAt(i)=='(')
      b = dfs(i+1, acc+1);
    else if (s.charAt(i)==')')
      b = dfs(i+1, acc-1);
    else
      b = dfs(i+1, acc+1) || dfs(i+1, acc-1) || dfs(i+1, acc);
    return b;
  }
}