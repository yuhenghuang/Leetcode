class ValidPalindrome {
  public static void main(String[] args) {
    ValidPalindrome obj = new ValidPalindrome();
    System.out.println(obj.isPalindrome("0P"));
  }
  public boolean isPalindrome(String s) {
    int l = 0, r = s.length()-1;
    while (l<r) {
      while (l<r && !Character.isLetterOrDigit(s.charAt(l)))
        ++l;
      while (r>l && !Character.isLetterOrDigit(s.charAt(r)))
        --r;
      // int diff = (s.charAt(l) - 'A') - (s.charAt(r) - 'A');
      if (Character.toLowerCase(s.charAt(l))!=Character.toLowerCase(s.charAt(r)))
        return false;
      ++l; --r;
    }
    return true;
  }
}