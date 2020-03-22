import java.util.Arrays;
import java.util.Queue;
import java.util.PriorityQueue;

public class CourseScheduleIII {
  public static void main(String[] args) {
    CourseScheduleIII obj = new CourseScheduleIII();
    int[][] courses = new int[][] {{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};
    System.out.println(obj.scheduleCourse(courses));
  }

  public int scheduleCourse(int[][] courses) {
    Arrays.sort(courses, (a, b) -> a[1]-b[1]);
    int res=0, sum=0;
    Queue<Integer> heap = new PriorityQueue<>((a, b) -> b-a);
    for (int[] course : courses) {
      if (course[1]>=sum+course[0]) {
        heap.offer(course[0]);
        sum+=course[0];
        res++;
      }
      else if (!heap.isEmpty() && heap.peek()>course[0]){
        sum+=course[0]-heap.poll();
        heap.offer(course[0]);
      }
    }
    return res;
  }
}