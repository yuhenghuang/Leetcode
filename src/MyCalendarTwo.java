import java.util.*;

public class MyCalendarTwo {
  List<int[]> calendar;
  List<int[]> overlapped;
  public MyCalendarTwo() {
    calendar = new ArrayList<>();
    overlapped = new ArrayList<>();
  }
  
  public boolean book(int start, int end) {
    for (int[] iv : overlapped)
      if (start<iv[1] && end>iv[0])
        return false;
    
    for (int[] iv : calendar)
      if (start<iv[1] && end>iv[0])
        overlapped.add(new int[]{Math.max(start, iv[0]), Math.min(end, iv[1])});
    calendar.add(new int[]{start, end});
    return true;
  }
}