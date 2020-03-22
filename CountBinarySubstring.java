public class CountBinarySubstring {
  public static void main(String[] args) {
    CountBinarySubstring obj = new CountBinarySubstring();
    String input = "";
    int res = obj.countBinarySubstrings(input);
    System.out.println(res);
  }
  public int countBinarySubstrings(String s) {
    int res = 0, prev0=0, prev1=0;
    for (int i=0; i<s.length(); ++i) {
      if (s.charAt(i)=='0') {

        if (prev1>0) {
          prev1--;
          res++;
        }
        if (i>0 && s.charAt(i-1)=='1')
          prev0=0;
        prev0++;
      }
      else {
        if (prev0>0) {
          prev0--;
          res++;
        }
        if (i>0 && s.charAt(i-1)=='0')
          prev1=0;
        prev1++;
      }
    }
    return res;
  }
}