class LongestPalindrome {
  public int longestPalindrome(String s) {
    int[] count = new int[58];
    for (int i=0; i<s.length(); ++i)
      ++count[s.charAt(i)-'A'];

    int res = 0;
    for (int i=0; i<58; ++i)
      if (count[i]%2==1) {
        ++res;
        break;
      }

    for (int i=0; i<58; ++i)
      res += (count[i] / 2) * 2;
    return res;
  }
}