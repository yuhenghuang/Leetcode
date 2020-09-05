class RepeatedSubstringPattern {
  public static void main(String[] args) {
    RepeatedSubstringPattern obj = new RepeatedSubstringPattern();
    System.out.println(obj.repeatedSubstringPattern("ababa"));
  }
  public boolean repeatedSubstringPattern(String s) {
    return s.matches("^([a-z]+)(\\1)+$");
  }
}