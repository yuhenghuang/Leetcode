import java.util.Arrays;
import java.util.LinkedList;

public class DominoTromino {
  long mod= (long) 1e9+7;
  public int numTilings(int N) {
    LinkedList<Long> dp = new LinkedList<>(Arrays.asList(1L, 2L, 5L, 11L));
    if (N<4) return dp.get(N-1).intValue();

    long res=5;
    long acc=1;
    for (int i=4; i<N; ++i) {
      acc+=dp.poll() % mod;
      res+=acc*2 % mod;
      res=(res+dp.peek()*2) % mod;
      res=(res+dp.get(1)) % mod;

      dp.add(res);
    }

    return (int) res;
  }
}