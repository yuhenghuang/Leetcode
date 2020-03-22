public class MaxGap {
  public static void main(String[] args) {
    MaxGap obj = new MaxGap();
    System.out.println(obj.maximumGap(new int[] {3,6,9,1}));
  }
  public int maximumGap(int[] nums) {
    if (nums.length<2) return 0;
    int min=Integer.MAX_VALUE, max=Integer.MIN_VALUE, n=nums.length;
    for (int num:nums) {
      if (num<min) min=num;
      if (num>max) max=num;
    }

    int b=Math.max(1, (max-min)/(n-1));
    int k=(max-min)/b + 1;
    Bucket[] buckets = new Bucket[k];
    for (int i=0; i<k; i++) buckets[i]= new Bucket();
    for (int num:nums) {
      int idx=(num-min)/b;
      //System.out.println(idx+" "+num);
      buckets[idx].setMinMax(num);
    }

    int lastMax=min, res=0;
    for (Bucket bucket:buckets)
      if (bucket.used) {
        res = Math.max(bucket.min-lastMax, res);
        lastMax=bucket.max;
      }
    return res;
  }

  class Bucket {
    boolean used;
    int min, max;
    
    Bucket() {
      used=false;
      min=Integer.MAX_VALUE;
      max=Integer.MIN_VALUE;
    }


    public void setMinMax(int num) {
      used=true;
      min = Math.min(num, min);
      max = Math.max(num, max);
    }
  }
}