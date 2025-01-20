public class ReverseWordsinString {
  public String reverseWords(String s) {
    StringBuffer res = new StringBuffer();

    int idx=s.length();
    StringBuffer strBuf = new StringBuffer(" ");
    while (--idx>=0) {
      if (s.charAt(idx)==' ') {
        if (strBuf.length()>0) {
          res.append(strBuf.toString());
          strBuf = new StringBuffer(" ");
        } 
      }
      else {
        strBuf.insert(0, s.charAt(idx));
        if (idx==0) res.append(strBuf.toString());
      }
    }
    return res.length()>0?res.substring(0, res.length()-1).toString():res.toString();
  }
}