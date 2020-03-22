public class MinCostTree {
    public static void main(String[] args) {
        MinCostTree sol = new MinCostTree();
        int[] arr = new int[] {1,3,5,7,2,8,9,10,12,4,6,11,13};
        System.out.println(sol.mctFromLeafValues(arr));
    }

    int[][] memo;
    public int mctFromLeafValues(int[] arr) {
        memo = new int[arr.length][arr.length];
        return dp(arr, 0, arr.length-1);
    }

    public int dp(int[] arr, int i, int j) {
        if (memo[i][j]!=0) return memo[i][j];

        int res=Integer.MAX_VALUE;
        if (j>i) {
            int l=0;
            int r=0;
            for (int k=i; k<j; k++) {
                for (int m=i; m<=k; m++) {
                    l=Math.max(l, arr[m]);
                }
                for (int n=k+1; n<=j; n++) {
                    r=Math.max(r, arr[n]);
                }
                res=Math.min(res, dp(arr, i, k) + dp(arr, k+1, j) + l * r);
            }
        }
        else {
            res=0;
        }
        memo[i][j]=res;
        return res;
    }
}