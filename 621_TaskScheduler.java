import java.util.Arrays;


class TaskScheduler {
  public static void main(String[] args) {
    TaskScheduler obj = new TaskScheduler();
    char[] tasks = new char[] {'A', 'A','A','B','B','B', 'C', 'C', 'D', 'D'};
    System.out.println(obj.leastInterval(tasks, 4));
  }
  public int leastInterval(char[] tasks, int n) {
    int[] freq = new int[26];
    for (char c : tasks)
      ++freq[c-'A'];

    int max_freq = Arrays.stream(freq).max().getAsInt();

    int inc = 0, idle_time = (max_freq-1) * (n+1) + 1;
    for (int cnt : freq)
      if (cnt==max_freq)
        ++inc;

    return Math.max(idle_time+inc-1, tasks.length);
  }
}