class PerformStringShifts {
  public String stringShift(String s, int[][] shift) {
    int N = s.length();
    int sf = 0;
    for (int[] move: shift) {
      if (move[0]==1)
        sf-=move[1];
      else
        sf+=move[1];
    }

    sf %= N;
    if (sf<0)
      sf+=N;
    return s.substring(sf) + s.substring(0, sf);
  }
}