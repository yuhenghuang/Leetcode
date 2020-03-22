import java.util.Deque;
import java.util.ArrayDeque;

public class SlidingWindowMax {
  public static void main(String[] args) {
    SlidingWindowMax obj = new SlidingWindowMax();
    int[] res = obj.maxSlidingWindow(new int[] {1,3,-1,-3,5,3,6,7}, 3);
    for (int num : res) System.out.print(num+"\t");
    System.out.println("");
  }

  public int[] maxSlidingWindow(int[] nums, int k) {
    //not finished
    int n=nums.length;
    if (n==0) return nums;
    int [] res = new int[n-k+1];
    int mp=0;
    for (int i=0; i<n; i++) {
      if (i-k>=mp) mp++;

    }
    return res;
  }


  
  public int[] maxSlidingWindowPair(int[] nums, int k) {
    int n=nums.length;
    if (n==0) return nums;
    Deque<Pair> queue = new ArrayDeque<>();
    int [] res = new int[n-k+1];
    for (int i=0; i<n; i++) {
      if (!queue.isEmpty() && i-k>=queue.peekFirst().idx) queue.pollFirst();
      Pair p = new Pair(i, nums[i]);

      while (!queue.isEmpty() && queue.peekLast().num<p.num)
        queue.pollLast();
      queue.addLast(p);

      if (i>=k-1) {
        res[i-k+1] = queue.peekFirst().num;
      }
    }
    return res;
  }

  class Pair {
    int idx, num;
    Pair(int i, int n) {
      idx=i;
      num=n;
    }
  }
}