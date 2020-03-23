import java.util.Arrays;

class RandomPointsRect {
  public static void main(String[] args) {
    int[][] rects = new int[][] {{1,1,5,5}, {10,10, 13, 13}};
    RandomPointsRect obj = new RandomPointsRect(rects);
    System.out.println(obj.cumsum[2]);
    for (int i=0; i<5; ++i) {
      int[] output = obj.pick();
      System.out.println(output[0]+","+output[1]);
    }
  }
  int[][] rects;
  int[] cumsum;
  public RandomPointsRect(int[][] rects) {
    cumsum = new int[rects.length+1];

    for (int i=1; i<=rects.length; ++i) {
      cumsum[i]=cumsum[i-1] + size(rects[i-1]);
    }

    this.rects = rects;
  }

  private int size(int[] rect) {
    return (rect[3]-rect[1]+1) * (rect[2]-rect[0]+1);
  }

  private int[] draw(int[] rect, int idx) {
    return new int[] {rect[0]+idx%(rect[2]-rect[0]+1), rect[1]+idx/(rect[2]-rect[0]+1)};
  }
  
  public int[] pick() {
    int rand = (int) (Math.random() * cumsum[rects.length]);
    int idx = Arrays.binarySearch(cumsum, rand);
    if (idx<0) idx=-idx-2;
    return draw(rects[idx], rand-cumsum[idx]);
  }
}