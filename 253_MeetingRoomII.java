import java.util.TreeMap;

class MeetingRoom {
  public static void main(String[] args) {
    int[][] itv = new int[][] {{0, 30}, {5,10}, {15,20}};
    MeetingRoom obj = new MeetingRoom();
    System.out.println(obj.minMeetingRooms(itv));
  }
  public int minMeetingRooms(int[][] intervals) {
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