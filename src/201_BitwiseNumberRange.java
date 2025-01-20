class BitwiseNumberRange {
  public static void main(String[] args) {
    BitwiseNumberRange obj = new BitwiseNumberRange();
    System.out.println(obj.rangeBitwiseAnd(7, 6));
  }
  public int rangeBitwiseAnd(int m, int n) {
    String strm = preprocess(m);
    String strn = preprocess(n);
    // System.out.println(strm);
    // System.out.println(strn);
    int res=0;
    for (int i=0; i<strm.length(); ++i) {
      if (strm.charAt(i)=='0' && strn.charAt(i)=='0') continue;
      else if (strm.charAt(i)=='1' && strn.charAt(i)=='1')
        res += 1 << (strm.length() - i - 1);
      else
        return res;
    }
    return res;
  }

  String preprocess(int i) {
    String s = Integer.toBinaryString(i);
    StringBuilder sb = new StringBuilder("");
    int pad = 32 - s.length();
    while (pad-->0) {
      sb.append('0');
    }
    sb.append(s);
    return sb.toString();
  }
}