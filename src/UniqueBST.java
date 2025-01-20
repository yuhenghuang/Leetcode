public class UniqueBST {
  public static void main(String[] args) {
    UniqueBST obj = new UniqueBST();
    System.out.println(obj.numTrees(10));
  }
  int[] memo;
  public int numTrees(int n) {
    memo = new int[n+1];
    return dp(n);
  }

  public int dp(int n) {
    if (n<2) return 1;
    else if (memo[n]>0) return memo[n];
    for (int i=0; i<n; i++)
      memo[n]+=dp(i)*dp(n-i-1);
    return memo[n];
  }
}