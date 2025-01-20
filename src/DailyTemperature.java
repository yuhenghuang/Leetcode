import java.util.Stack;

public class DailyTemperature {
  public static void main(String[] args) {
    DailyTemperature obj = new DailyTemperature();
    int[] res = obj.dailyTemperatures(new int[] {73, 74, 75, 71, 69, 72, 76, 73});
    for (int t:res) System.out.print(t+"\t");
    System.out.println("");
  }

  public int[] dailyTemperatures(int[] T) {
    int[] ans = new int[T.length];
    Stack<Integer> stack = new Stack<>();
    for (int i=T.length-1; i>=0; --i) {
      while (!stack.isEmpty() && T[stack.peek()]<=T[i])
        stack.pop();
      ans[i]=stack.isEmpty()?0:stack.peek()-i;
      stack.push(i);
    }
    return ans;
  }



  public int[] dailyTemperaturesO2(int[] T) {
    for (int i=0; i<T.length; ++i) {
      int res=0;
      for (int j=i+1; j<T.length; ++j)
        if (T[i]<T[j]) {
          res = j-i;
          break;
        }
      T[i]=res;
    }
    return T;
  }
}