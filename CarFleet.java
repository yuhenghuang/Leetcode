import java.util.Arrays;

public class CarFleet {
  public static void main(String[] args) {
    int a=3;
    int b=4;
    double c=(double) b/a;
    System.out.println(c+a);
  }
  public int carFleet(int target, int[] position, int[] speed) {
    int N = position.length;
    Pair[] cars = new Pair[N];
    for (int i=0; i<N; ++i) {
      cars[i] = new Pair(position[i], (double) (target-position[i]/speed[i]));
    }
    Arrays.sort(cars, (a, b) -> Integer.compare(a.position, b.position));

    int res=1;
    for (int i=N; i>0; --i) {
      if (cars[i].time>cars[i-1].time) res++;
      else cars[i-1]=cars[i];
    }
    return res;
  }
}

class Pair {
  int position;
  double time;
  Pair (int p, double t) {
    position=p;
    time=t;
  }
}
