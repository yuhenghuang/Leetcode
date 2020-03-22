import java.util.List;
import java.util.ArrayList;

public class GenerateParenthese {
  public static void main(String[] args) {
    GenerateParenthese obj = new GenerateParenthese();
    List<String> output = obj.generateParenthesis(2);
    for (String s : output) System.out.println(s);
  }
  int N;
  List<String> res;
  public List<String> generateParenthesis(int n) {
    N = 2*n;
    res = new ArrayList<>();
    StringBuilder sb = new StringBuilder();
    dfs(sb, n, n, 0);
    return res;
  }

  public void dfs(StringBuilder sb, int left, int right, int len) {
    if (len==N) {
      res.add(sb.toString());
      return;
    }
    else {
      if (left>0) {
        sb.append('(');
        dfs(sb, left-1, right, len+1);
        sb.deleteCharAt(len);
      }
      if (right>left) {
        sb.append(')');
        dfs(sb, left, right-1, len+1);
        sb.deleteCharAt(len);
      }
    }
  }
}