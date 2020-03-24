import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;

class BoatsSavePeople {
  public static void main(String[] args) {
    int[] pp = new int[] {3, 5, 3, 4};
    BoatsSavePeople obj = new BoatsSavePeople();
    System.out.println(obj.numRescueBoats(pp, 5));
  }
  public int numRescueBoats(int[] people, int limit) {
    Arrays.sort(people);
    int l=0, r=people.length-1, ans=0;
    while (l<=r) {
      int res = limit - people[r--];
      if (people[l]<=res) l++;
      ans++;
    }
    return ans;
  }
  public int numRescueBoatsDeque(int[] people, int limit) {
    Arrays.sort(people);
    Deque<Integer> deque = new ArrayDeque<>();
    for (int w : people)
      deque.offer(w);

    int ans=0;
    while (!deque.isEmpty()) {
      int res = limit - deque.pollLast();
      if (!deque.isEmpty() && deque.peekFirst()<=res)
        deque.pollFirst();
      ans++;  
    }
    return ans;
  }
}