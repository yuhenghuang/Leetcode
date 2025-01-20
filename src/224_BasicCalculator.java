import java.util.Stack;

class BasicCalculator {
  public static void main(String[] args) {
    BasicCalculator obj = new BasicCalculator();
    System.out.println(obj.calculate(" 2-1 + 2 "));
  }

  public int calculate(String s) {
    s = s.replaceAll("\s+", "");
    Stack<String> stack = new Stack<>();
    StringBuilder sb = new StringBuilder("");
    for (char c: s.toCharArray()) {
      if (!Character.isDigit(c)) {
        if (sb.length()!=0) {
          stack.push(sb.toString());
          sb = new StringBuilder("");
        }
        if (c==')') {
          inner(stack);
        }
        else
          stack.push(String.valueOf(c));
      }
      else {
        sb.append(c);
      }
    }

    if (sb.length()!=0) 
      stack.push(sb.toString());

    inner(stack);
    return Integer.valueOf(stack.pop());
  }

  void inner(Stack<String> stack) {
    String[] s;
    while (true) {
      int i=0;
      s = new String[3];
      while (i<3 && !stack.isEmpty()) {
        String temp = stack.pop();
        if (temp.equals("(")) break;
        s[i++] = temp;
      }
      String res;
      if (s[1]==null) break;
      else if (s[1].equals("+")) 
        res = String.valueOf(Integer.parseInt(s[2]) + Integer.parseInt(s[0]));
      else 
        res = String.valueOf(Integer.parseInt(s[2]) - Integer.parseInt(s[0]));
      stack.push(res);
    }
    stack.push(s[0]);
  }
}