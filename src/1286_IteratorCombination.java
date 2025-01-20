class CombinationIterator {
  public static void main(String[] args) {
    CombinationIterator obj = new CombinationIterator("abc", 2);
    System.out.println(obj.next());
    System.out.println(obj.hasNext());
    System.out.println(obj.next());    
    System.out.println(obj.hasNext());
    System.out.println(obj.next());
    System.out.println(obj.hasNext());
  }
  int s, n;
  boolean flag;
  String str;
  int[] idx;
  StringBuilder sb;
  public CombinationIterator(String characters, int combinationLength) {
    s = characters.length();
    n = combinationLength;
    str = characters;
    sb = new StringBuilder("");
    idx = new int[n];
    for (int i=0; i<n; ++i)
      idx[i] = i;

    flag = n<=s;
  }
  
  public String next() {
    sb.delete(0, sb.length());
    for (int i=0; i<n; ++i)
      sb.append(str.charAt(idx[i]));

    int stone = n-1;
    while (stone>=0 && idx[stone]>=s-n+stone)
      --stone;

    if (stone!=-1) {
      ++idx[stone];
      for (int i=stone+1; i<n; ++i)
        idx[i] = idx[stone] + i-stone;
    }
    else
      flag = false;
    return sb.toString();
  }
  
  public boolean hasNext() {
    return flag;
  }
}