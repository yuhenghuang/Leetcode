class BackspaceStrCompare {
  public static void main(String[] args) {
    BackspaceStrCompare obj = new BackspaceStrCompare();
    System.out.println(obj.backspaceCompare("a#c", "b"));
  }
  public boolean backspaceCompare(String S, String T) {
    S = process(S);
    T = process(T);
    return S.equals(T);
  }

  private String process(String s) {
    StringBuilder sb = new StringBuilder("");
    for (char c : s.toCharArray())
      if (c!='#')
        sb.append(c);
      else if (sb.length()>0)
        sb.deleteCharAt(sb.length()-1);
    return sb.toString();
  }
}