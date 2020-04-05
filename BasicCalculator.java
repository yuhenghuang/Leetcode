import java.util.Stack;

public class BasicCalculator {
  public static void main(String[] args) {
    Stack<Character> s1= new Stack<>();
    Stack<Character> s2= new Stack<>();
    s1.add('e');
    s2.add('1'); s2.add('2');
    s1.addAll(s2);
    System.out.println(s1);
  }

  int idx;
  public int calculate(String s) {
    StringBuilder sb = new StringBuilder("");
    Stack<Boolean> parStack = new Stack<>();
    for (int i=0; i<s.length(); ++i) {
      char c = s.charAt(i);
      if (c==' ') continue;
      else if (c=='(') {
        if (sb.length()==0 || sb.charAt(sb.length()-1)=='+') {
          parStack.add(false);
        }
        else {
          sb.append(" ( ");
          parStack.add(true);
        }
      }
      else if (c==')') {
        if (parStack.pop())
          sb.append(" ) ");
      }
      else if (c=='+'){
        sb.append(" + ");
      }
      else if (c=='-') {
        sb.append(" - ");
      }
      else {
        sb.append(c);
      }
    }
    s = sb.toString();
    String[] formula = s.split(" ");
    idx = formula.length;
    return recursive();
  }

  public Integer recursive() {
    //int res=0;
    // while (idx>=0 && formula.charAt(idx)!='(') {
    //   char c =formula.charAt(idx);
    //   if ()
    // }
    return null;
  }
}