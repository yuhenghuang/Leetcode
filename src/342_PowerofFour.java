class PowerOfFour {
  public boolean isPowerOfFour(int num) {
    int zeros = 0;
    while (num>0 && (num & 1)==0) {
      ++zeros;
      num >>= 1;
    }
    return num==1 && zeros % 2 == 0;
  }
}