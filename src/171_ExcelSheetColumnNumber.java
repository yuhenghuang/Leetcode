class ExcelSheetColumnNumber {
  public static void main(String[] args) {
    ExcelSheetColumnNumber obj = new ExcelSheetColumnNumber();
    System.out.println(obj.titleToNumber("ZY"));
  }
  public int titleToNumber(String s) {
    int n = s.length();
    int base=1, res=0;
    for (int i=0; i<n; ++i) {
      res += (s.charAt(n-i-1) - 'A' + 1) * base;
      base *= 26;
    }
    return res;
  }
}