class MinKnightMoves {
  public static void main(String[] args) {
    MinKnightMoves obj = new MinKnightMoves();
    System.out.println(obj.minKnightMoves(120, 100));
  }
  public int minKnightMoves(int x, int y) {
    int res=0;
    return res;
  }

  public int minKnightMovesMath(int x, int y) {
    x = Math.abs(x);
    y = Math.abs(y);
    if (y>x) {
      int temp=x;
      x=y;
      y=temp;
    }

    int res=0;
    while (x>0 && y>0) {
      if (2*y>x) {
        x--;
        y-=2;
      }
      else {
        y--;
        x-=2;
      }
      res++;
    }

    if (x!=0 || y!=0)
      res+=1;
    return res; 
  }
}