public class TrappingWater {
  public static void main(String[] args) {
    TrappingWater obj = new TrappingWater();
    System.out.println(obj.trap(new int[] {0,1,0,2,1,0,1,3,2,1,2,1}));
  }
  public int trap(int[] height) {
    int i=0, j=0, n=height.length;
    if (n==0) return 0;
    int res=0;
    int [] forward, backward;
    forward = new int[n];
    backward = new int[n];
    while (j<n) {
      while(i<n-1 && height[i]<=height[i+1]) i++;
      j=i+1;
      while(j<n && height[j]<=height[i]) {
        forward[j]=height[i]-height[j];
        j++;
      }
      i=j;
    }

    i=n-1; j=n-1;
    while (j>0) {
      while(i>0 && height[i]<=height[i-1]) i--;
      j=i-1;
      while(j>0 && height[j]<=height[i]) {
        backward[j]=height[i]-height[j];
        j--;
      }
      i=j;
    }

    for (int k=0; k<n; ++k){
      //System.out.println(forward[k]+" "+backward[k]);
      res+=Math.min(forward[k], backward[k]);
    }
    return res;
  }
}