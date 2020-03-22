import java.util.*;

public class KthLargestElement {
  public static void main(String[] args) {
    KthLargestElement obj = new KthLargestElement();
    int[] nums = new int[] {3,2,3,1,2,4,5,5,6};
    System.out.println(obj.findKthLargest(nums, 4));
  }

  public int findKthLargest(int[] nums, int k) {
    Queue<Integer> heap = new PriorityQueue<>();
    for (int i=0; i<k; ++i)
      heap.offer(nums[i]);

    for (int i=k; i<nums.length; ++i)
      if (nums[i]>heap.peek()) {
        heap.poll();
        heap.offer(nums[i]);
      }
    return heap.peek();
  }
}