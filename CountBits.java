public class CountBits {
  public static void main(String[] args) {
    CountBits obj = new CountBits();
    int [] res = obj.countBits(12);
    for (int n : res) System.out.print(n+"\t");
  }
  public int[] countBits(int num) {
    int[] res = new int[num+1];
    res[0]=0;
    int base=1;
    while (num>0) {
      for (int i=0; i<Math.min(base, num); ++i) {
        res[base+i]=res[i]+1;
      }
      num-=base;
      base*=2;
    }
    return res;
  }
}