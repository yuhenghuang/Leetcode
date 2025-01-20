class ValidPerfectSquare {
  public static void main(String[] args) {
    ValidPerfectSquare sol = new ValidPerfectSquare();
    System.out.println(sol.isPerfectSquare(123));
  }
  public boolean isPerfectSquare(int num) {
    int l=1, r=num;
    while (l < r) {
      int m = l + (r-l)/2;
      if (m < (num / m))
        l = m+1;
      else
        r = m;
    }
    return l*l == num;
  }
}