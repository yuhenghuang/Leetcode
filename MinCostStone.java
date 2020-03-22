public class MinCostStone {
    public static void main(String[] args) {
        MinCostStone sol = new MinCostStone();
        int[] stones = new int[] {4, 1, 2, 3,5};
        System.out.println(sol.mergeStones(stones, 3));
    }
    
    int[][] memo;
    int[] cumSum;
    public int mergeStones(int[] stones, int K) {
        if (stones.length==1 || K==0) return 0;
        if ((stones.length-1) % (K-1)!=0) return -1;
        
        memo = new int[stones.length][stones.length];
        cumSum = new int[stones.length+1];

        for (int i=1; i<=stones.length; i++) {
            cumSum[i] = cumSum[i-1] + stones[i-1];
        }

        for (int r=0; r<stones.length; r++) {
            for (int l=r-K+1; l>=0; --l) {
                int res = Integer.MAX_VALUE;
                for (int p=r; p>l; p-=K-1) {
                    res = Math.min(res, memo[l][p-1]+memo[p][r]);
                    memo[l][r]=res;
                }
                if ((l-r)%(K-1)==0) memo[l][r]+=cumSum[r+1]-cumSum[l];
            }
        }
        return memo[0][stones.length-1];
    }
}