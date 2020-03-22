
public class RandomPointInCircle {
  public static void main(String[] args) {
    RandomPointInCircle obj = new RandomPointInCircle(10, 5, -7.5);
    int N=5;
    while (N-->0)
      obj.randPoint();
  }
  double r, xC, yC;
  public RandomPointInCircle(double radius, double x_center, double y_center) {
    r=radius;
    xC=x_center;
    yC=y_center;
  }

  public double[] randPoint() {
    double theta=2*Math.PI*(Math.random()-0.5), dist=Math.sqrt(Math.random());
    double x=Math.cos(theta)*dist, y=Math.sin(theta)*dist;
    double[] res=new double[]{xC+r*x, yC+r*y};
    //System.out.println(res[0]+" "+res[1]);
    return res;
  }


  
  public double[] randPoint_xy() {
    double tempX=Math.random()-0.5, tempY=(Math.random()-0.5)*2;
    double x=binarySearch(tempX);
    double y=Math.sqrt(1-x*x)*tempY;
    double[] res=new double[]{xC+r*x, yC+r*y};
    System.out.println(res[0]+" "+res[1]);
    return res;
  }

  private double binarySearch(double target) {
    double left=-1, right=1, err=1, x=0;
    while (Math.abs(err)>1e-8) {
      x=(left+right)/2;
      err=cdf(x)-target;
      if (err>0)
        right=x;
      else
        left=x;
    }
    return x;
  }

  private double cdf(double x) {
    return  (x*Math.sqrt(1-x*x)+Math.asin(x))/Math.PI;
  }
}