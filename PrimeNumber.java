import java.util.ArrayList;
import java.util.List;

class PrimeNumber {
  public static void main(String[] args) {
    int N = 10000;
    List<Integer> list = new ArrayList<>();
    int count=0;
    for (int i=2; i<N; ++i) {
      boolean flag = true;
      for (int p : list) {
        if (p * p> i) break;
        if (i % p==0) {
          flag=false;
          break;
        }
      }
      if (flag) {
        list.add(i);
        System.out.print(i+"\t");
        count++;
        if (count % 14==0) {
          System.out.println("");
        }
      }
    }
  }
}