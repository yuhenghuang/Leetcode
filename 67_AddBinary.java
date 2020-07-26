class AddBinary {
  public static void main(String[] args) {
    AddBinary obj = new AddBinary();
    System.out.println(obj.addBinary("1010", "1011"));
  }
  public String addBinary(String a, String b) {
    if (a.length() < b.length()) {
      String temp = a;
      a = b;
      b = temp;
    }

    int m = a.length(), n = b.length();
    char[] res = a.toCharArray();

    int rem = 0;
    for (int i=1; i<=n; ++i) {
      rem += res[m-i] - '0' + b.charAt(n-i) - '0';
      res[m-i] = (char) (rem % 2 + '0');
      rem /= 2;
    }

    int idx = m-n-1;
    if (rem==1) {
      while (idx>=0 && res[idx]=='1') {
        res[idx] = '0';
        --idx;
      }

      if (idx>=0)
        res[idx] = '1';
    }

    String ans = new String(res);
    if (idx==-1 && rem==1)
      ans = "1" + ans;
    return ans;
  }
}