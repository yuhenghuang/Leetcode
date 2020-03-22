import java.util.*;

public class MaxLenPairChain {
  public int findLongestChain(int[][] pairs) {
    Arrays.sort(pairs, (a, b) -> a[1]-b[1]);
    int ans=0, cur=Integer.MIN_VALUE;
    for (int[] pair : pairs)
      if (pair[0]>cur) {
        cur=pair[1];
        ans++;
      }
    return ans;
  }


  public int findLongestChainDP(int[][] pairs) {
    int N = pairs.length;
    Arrays.sort(pairs, (a, b) -> a[0]-b[0]);

    int ans=0;
    int[] memo = new int[N];
    for (int i=N-1; i>=0; --i) {
      int res=1;
      for (int j=i+1; j<N; ++j) 
        if (pairs[i][1]<pairs[j][0])
          res=Math.max(res, 1+memo[j]);
      ans=Math.max(ans, res);
      memo[i]=res;
    }
    return ans;
  }
}