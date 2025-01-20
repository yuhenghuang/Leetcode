import java.util.*;

public class MyCalendarI {
  List<Integer> calendar;
  TreeMap<Integer, Integer> tree;

  public MyCalendarI() {
    calendar = new ArrayList<>();
    tree = new TreeMap<>();
  }

  public boolean book(int start, int end) {
    Integer prev = tree.ceilingKey(start);
    Integer next = tree.floorKey(start);
    if ((prev==null || tree.get(prev)<=start) && (next==null || next>=end)) {
      tree.put(start, end);
      return true;
    }
    return false;
  }
  




  public boolean book_list(int start, int end) {
    if (calendar.isEmpty() || calendar.get(calendar.size()-1)<=start) {
      calendar.add(start);
      calendar.add(end);
      return true;
    }
    else if (calendar.get(0)>=end){
      calendar.add(0, end);
      calendar.add(0, start);
      return true;
    }
    else {
      for (int i=2; i<calendar.size(); i+=2) {
        if (calendar.get(i)>=end && calendar.get(i-1)<=start) {
          calendar.add(i, end);
          calendar.add(i, start);
          return true;
        }
      }
      return false;
    }
  }
}