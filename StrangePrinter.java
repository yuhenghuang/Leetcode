public class StrangePrinter {
  int[][] memo;
  String s;
  public int strangePrinter(String s) {
    StringBuffer s_new = new StringBuffer();
    for (int i=0; i<s.length(); ++i) {
      if (s_new.length()==0 || s.charAt(i)!=s_new.charAt(s_new.length()-1)) {
        s_new.append(s.charAt(i));
      }
    }

    this.s=s_new.toString();
    int N = this.s.length();
    memo = new int[N][N];
    return dfs(0, N-1);
  }

  public int dfs(int i, int j) {
    if (i>j) return 0;
    if (memo[i][j]!=0) return memo[i][j];
    int res=1 + dfs(i+1, j);
    for (int k=i+1; k<=j; ++k) {
      if (s.charAt(i)==s.charAt(k)) 
        res=Math.min(res, dfs(i, k-1) + dfs(k+1, j));
    }
    memo[i][j]=res;
    return res;
  }
}