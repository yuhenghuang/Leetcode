
public class CanIWin {
  public static void main(String[] args) {
    CanIWin obj = new CanIWin();
    System.out.println(obj.canIWin(10, 19));
  }
  boolean[] can;
  int[] memo1, memo2;
  int target, N;
  public boolean canIWin(int maxChoosableInteger, int desiredTotal) {
    target = desiredTotal;
    N = maxChoosableInteger;
    can = new boolean[N+1];
    can[0]=true;
    memo1 = new int[target+1];
    memo2 = new int[target+1];
    return minimax(0, true);
  }

  public boolean minimax(int total, boolean p1) {
    boolean next=false;
    if (total>=target) 
      if (!p1) return true;
      else return false;
    else {
      for (boolean b : can)
        if (!b) {next=true;break;}
      if (!next) return false;
    }

    if (p1) {
      if (memo1[total]>0)
        return memo1[total]==1?true:false;
      next=false;
      for (int i=1; i<=N; ++i) {
        if (!can[i]) {
          can[i]=true;
          next = minimax(total+i, false);
          can[i]=false;
          if (next) break;
        }
      }
      memo1[total]=next?1:2;
      return next;
    }
    else {
      if (memo2[total]>0)
        return memo2[total]==1?true:false;
      next=true;
      for (int i=1; i<=N; ++i) {
        if (!can[i]) {
          can[i]=true;
          next = minimax(total+i, true);
          can[i]=false;
          if (!next) break;
        }
      }
      memo2[total]=next?1:2;
      return next;
    }
  }
}