public class CountPrimes {
  public static void main(String[] args) {
    CountPrimes obj = new CountPrimes();
    System.out.println(obj.countPrimes(499979));
  }
  public int countPrimes(int n) {
    boolean[] mark = new boolean[n];

    for (int i=2; i*i<n; ++i) {
      if (!mark[i]) {
        for (int j=i*i; j<n; j+=i) 
          mark[j]=true;
      }
    }

    int res=0;
    for (int i=2; i<n; ++i)
      if (!mark[i]) res++;

    return res;
  }
}