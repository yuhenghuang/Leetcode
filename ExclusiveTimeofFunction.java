import java.util.List;
import java.util.Stack;

public class ExclusiveTimeofFunction {
    public int[] exclusiveTime(int n, List<String> logs) {
        int[] ans = new int[n];
        Stack<Integer> stack = new Stack<>();

        String[] three;
        int time=0;
        for (String log : logs) {
            three = log.split(":");

            if (three[1].equals("start")) {
                if (!stack.empty()) {
                    ans[stack.peek()]+=Integer.parseInt(three[2])-time;
                }
                stack.push(Integer.parseInt(three[0]));
                time=Integer.parseInt(three[2]);
            }
            else {
                ans[stack.pop()]+=Integer.parseInt(three[2]) - time +1;
                time=Integer.parseInt(three[2])+1;
            }
        }
        return ans;
    }
}