class CheckStraightLine {
  public boolean checkStraightLine(int[][] coordinates) {
    int N = coordinates.length;
    if (N<3) return true;
    int a = coordinates[1][1] - coordinates[0][1], b = coordinates[1][0] - coordinates[0][0];
    int c = b * coordinates[0][1] - a * coordinates[0][0];
    for (int i=2; i<N; ++i)
      if (b * coordinates[i][1] - a * coordinates[i][0] != c)
        return false;
    return true;
  }
}