public class OnesAndZeros {
  int[][] memo, counter;
  public int findMaxForm(String[] strs, int m, int n) {
    memo = new int[m][n];
    counter = new int[m][n];
    for (String s : strs) {
      int zeros=0, ones=0;
      for (int i=0; i<s.length(); ++i) {
        if (s.charAt(i)=='0') zeros++;
        else ones++;
      }
      if (zeros<m && ones<n)
        counter[zeros][ones]+=1;
    }
    return dfs(m, n, 0);
  }

  public int dfs(int m, int n, int count) {
    if (memo[m][n]>count)
      return memo[m][n];

    memo[m][n]=count;

    int res=count;
    for (int i=0; i<m; ++i)
      for (int j=0; j<n; ++j)
        if (counter[i][j]>0) {
          counter[i][j]--;
          res = Math.max(res, dfs(m-i, n-j, count+1));
          counter[i][j]++;
        }
    return res;
  }
}