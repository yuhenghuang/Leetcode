import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.TreeMap;

class MeetingRoom {
  public static void main(String[] args) {
    int[][] itv = new int[][] {{13, 15}, {1,13}};
    MeetingRoom obj = new MeetingRoom();
    System.out.println(obj.minMeetingRooms(itv));
  }
  public int minMeetingRooms(int[][] intervals) {
    Arrays.sort(intervals, (a,b) -> a[0]-b[0]);
    Queue<int[]> heap = new PriorityQueue<>(
      (a,b) -> a[1] - b[1]
    );

    int res=0;
    for (int[] meeting : intervals) {
      while(!heap.isEmpty() && heap.peek()[1]<=meeting[0])
        heap.poll();
      heap.offer(meeting);
      res=Math.max(res, heap.size());
    }
    return res;
  }

  public int minMeetingRoomsTreeMap(int[][] intervals) {
    TreeMap<Integer, Integer> treemap = new TreeMap<>();
    for (int[] meeting : intervals) {
      treemap.put(meeting[0], treemap.getOrDefault(meeting[0], 0)+1);
      treemap.put(meeting[1], treemap.getOrDefault(meeting[1], 0)-1);
    }

    int res=0, sum=0;
    for (int cnt : treemap.values()) {
      sum+=cnt;
      res=Math.max(res, sum);
    }
    return res;
  }
}