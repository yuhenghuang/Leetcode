import java.util.Arrays;
import java.util.PriorityQueue;

class LastStoneWeight {
  public int lastStoneWeight(int[] stones) {
    Arrays.sort(stones);
    int l=0, r=0;
    // unfinished
    return Math.abs(l-r);
  }

  public int lastStoneWeightHeap(int[] stones) {
    PriorityQueue<Integer> heap = new PriorityQueue<>((a, b) -> b-a);
    for (int w : stones)
      heap.offer(w);

    while (heap.size()>1) {
      int p = heap.poll();
      int q = heap.poll();
      if (p!=q)
        heap.offer(Math.abs(p-q));
    }
    return heap.isEmpty()?0:heap.poll();
  }
}