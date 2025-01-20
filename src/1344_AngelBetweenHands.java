class AngelBetweenHands {
  public static void main(String[] args) {
    AngelBetweenHands obj = new AngelBetweenHands();
    System.out.println(obj.angleClock(12, 30));
    System.out.println(obj.angleClock(3, 30));
    System.out.println(obj.angleClock(3, 15));
    System.out.println(obj.angleClock(4, 50));
    System.out.println(obj.angleClock(12, 0));
  }
  public double angleClock(int hour, int minutes) {
    double h = hour * 30 + (double) minutes / 2;
    double res = Math.abs(minutes * 6 - h);
    return res > 180 ? 360 - res : res;
  }
}