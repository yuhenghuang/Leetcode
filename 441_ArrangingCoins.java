class ArrangingCoins {
  public static void main(String[] args) {
    ArrangingCoins obj = new ArrangingCoins();
    System.out.println(obj.arrangeCoins(5));
    String a = "aa";
    String b = "a";
    String c = a+b;
    System.out.println("aaa"==c);
  }
  public int arrangeCoins(int n) {
    long x = n;
    x *= 8;
    return (int) ((Math.sqrt(x+1) - 1)/2);
  }
}