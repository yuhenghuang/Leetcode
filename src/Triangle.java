//import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;


public class Triangle {
  public int minimumTotal(List<List<Integer>> triangle) {
    int N = triangle.size();
    int[] dp = new int[N];
    for (int i=0; i<N; ++i)
      dp[i]=triangle.get(N-1).get(i);

    for (int i=N-2; i>=0; --i) {
      for (int j=0; j<=i; ++j) {
        dp[j]=Math.min(dp[j], dp[j+1]) + triangle.get(i).get(j);
      }
    }
    return dp[0];
  }

  public int minimumTotalUpdateSelf(List<List<Integer>> triangle) {
    int N = triangle.size();

    for (int i=N-2; i>=0; --i) {
      List<Integer> temp = new ArrayList<>();
      for (int j=0; j<=i; ++j) {
        temp.add(Math.min(triangle.get(i+1).get(j), triangle.get(i+1).get(j+1))+ triangle.get(i).get(j));
      }
      triangle.set(i, temp);
    }
    return triangle.get(0).get(0);
  }

  public int minimumTotalBottomUp(List<List<Integer>> triangle) {
    int N = triangle.size();
    int[][] dp = new int[N][N];
    for (int i=0; i<N; ++i)
      dp[N-1][i]=triangle.get(N-1).get(i);

    for (int i=N-2; i>=0; --i) {
      for (int j=0; j<=i; ++j) {
        dp[i][j]=Math.min(dp[i+1][j], dp[i+1][j+1]) + triangle.get(i).get(j);
      }
    }
    return dp[0][0];
  }


  public int minimumTotalTopDown(List<List<Integer>> triangle) {
    int N = triangle.size();
    int[][] dp = new int[N][N];
    dp[0][0]=triangle.get(0).get(0);
    for (int i=1; i<N; ++i) {
      dp[i][0]=dp[i-1][0]+triangle.get(i).get(0);
      dp[i][i]=dp[i-1][i-1]+triangle.get(i).get(i);
      for (int j=1; j<i; j++) {
        dp[i][j]=Math.min(dp[i-1][j-1], dp[i-1][j])+triangle.get(i).get(j);
      }
    }
    for (int i=0;i<N;i++)
      for (int j=0;j<N;j++)
        System.out.println(dp[i][j]+'\t');

    int res=Integer.MAX_VALUE;
    for (int num:dp[N-1])
      if (num<res)
        res=num;
    return res;
  }
}