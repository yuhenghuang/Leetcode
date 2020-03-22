import java.util.TreeMap;

public class MyCalendarThree {
  TreeMap<Integer, Integer> calendar;
  public MyCalendarThree() {
    calendar = new TreeMap<>();
  }
  
  public int book(int start, int end) {
    calendar.put(start, calendar.getOrDefault(start, 0)+1);
    calendar.put(end, calendar.getOrDefault(end, 0)-1);
    int res=0;
    int multi=0;
    for (int d : calendar.values()) {
      multi+=d;
      res=Math.max(res, multi);
    }
    return res;
  }
}