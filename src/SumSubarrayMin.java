import java.util.Stack;

public class SumSubarrayMin {
  public int sumSubarrayMins(int[] A){
    int n = A.length;
    if (n==0) return 0;
    long res=0;
    int mod= (int) 1e9+7, dot=0;

    Stack<Pair> stack = new Stack<>();
    for (int i=0; i<n; ++i) {
      int count=1;
      while (!stack.isEmpty() && stack.peek().val>=A[i]) {
        Pair p = stack.pop();
        count += p.count;
        dot -= p.val * p.count;
      }
      stack.push(new Pair(A[i], count));
      dot += A[i] * count;
      res += dot;
      res %= mod;
    }

    return (int) res;
  }

  class Pair {
    int count, val;
    Pair(int v, int c) {
      count=c;
      val=v;
    }
  }

  public int sumSubarrayMinsPrevNext(int[] A) {
    int n = A.length;
    if (n==0) return 0;
    long res=0;
    int mod= (int) 1e9+7;
    int[] prev=new int[n], next=new int[n];
    Stack<Integer> stack = new Stack<>();
    for (int i=0; i<n; i++) {
      while (!stack.isEmpty() && A[i]<=A[stack.peek()]) stack.pop();
      prev[i]=stack.isEmpty()?-1:stack.peek();
      stack.push(i);
    }

    stack = new Stack<>();
    for (int i=n-1; i>=0; i--) {
      while (!stack.isEmpty() && A[i]<=A[stack.peek()]) stack.pop();
      next[i]=stack.isEmpty()?n:stack.peek();
      stack.push(i);
    }

    for (int i=0; i<n; i++) {
      res+=(i-prev[i]) * (next[i]-i) % mod * A[i] % mod;
      res%=mod;
    }

    return (int) res;
  }

  public int sumSubarrayMinsTLE(int[] A) {
    int n = A.length;
    if (n==0) return 0;
    long res=0, mod= (int) 1e9+7;
    int[] dp = A.clone();
    for (int num: A) res+=num;

    for (int i=1; i<n; i++) {
      for (int j=0; j<n-i; j++) {
        dp[j]=Math.min(dp[j], A[j+i]);
        res+=dp[j];
      }
      res%=mod;
    }
    return (int) res;
  }
}