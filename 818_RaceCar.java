import java.util.PriorityQueue;

class RaceCar {
  public static void main(String[] args) {
    RaceCar obj = new RaceCar();
    System.out.println(obj.racecar(-140));
  }
  public int racecar(int target) {
    if (target==0) return 0;
    int tar = Math.abs(target);
    boolean[][] visited = new boolean[tar+1][tar+1];
    PriorityQueue<int[]> heap = new PriorityQueue<>(
      (a, b) -> b[1]-a[1]
    );

    heap.offer(new int[] {0, 1, target>=0?0:1});
    visited[0][1] = true;
    while (!heap.isEmpty()) {
      int[] rec = heap.poll();
      int posi = rec[0] + rec[1], sp = rec[1] * 2, count=rec[2]+1;
      if (posi>tar) {
        posi = 2 * tar - posi;
        sp = 1;
        count++;
      }
      if (posi==tar)
        return count;
      //System.out.println(posi+" "+sp+" "+count);
      if (!visited[posi][sp]) {
        heap.offer(new int[] {posi, sp, count});
        visited[posi][sp]=true;
      }
    }
    return 0;
  }
}