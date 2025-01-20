public class ChampagneTower {
  public static void main(String[] args) {
    ChampagneTower obj = new ChampagneTower();
    System.out.println(obj.champagneTower((int) 50, 10, 7));
  }
  double memo[][];
  boolean seen[][];
  public double champagneTower(int poured, int query_row, int query_glass) {
    memo = new double[query_row+1][query_row+1];
    seen = new boolean[query_row+1][query_row+1];

    memo[0][0] = (double) poured;
    seen[0][0] = true;
    double res = recursive(query_row, query_glass);
    return res>1?1:res;
  }

  public double recursive (int query_row, int query_glass) {
    if (seen[query_row][query_glass]) return memo[query_row][query_glass];
    double res;
    if (query_glass==0) {
      res = Math.max((recursive(query_row-1, query_glass)-1)*0.5, 0);
    }
    else if (query_glass==query_row) {
      res = Math.max((recursive(query_row-1, query_glass-1)-1)*0.5, 0);
    }
    else {
      res = Math.max((recursive(query_row-1, query_glass-1)-1)*0.5, 0) + Math.max((recursive(query_row-1, query_glass)-1)*0.5, 0);
    }
    memo[query_row][query_glass]=res;
    seen[query_row][query_glass]=true;
    return res;
  }
}