import java.util.List;
import java.util.ArrayList;
import java.util.Stack;
//import java.util.Queue;
//import java.util.ArrayDeque;

public class TreeZigZag {
  public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
    List<List<Integer>> res = new ArrayList<>();
    Stack<TreeNode> stack = new Stack<>();
    boolean sw = true;
    stack.push(root);
    while (!stack.isEmpty()) {
      int N=stack.size();
      List<Integer> sub = new ArrayList<>();
      Stack<TreeNode> stack2 = new Stack<>();
      while (N-->0) {
        root = stack.pop();
        if (root!=null) {
          System.out.println(root.val);
          sub.add(root.val);
          if (sw) {
            stack2.push(root.left);
            stack2.push(root.right);
          }
          else {
            stack2.push(root.right);
            stack2.push(root.left);
          }
        }
      }
      stack=stack2;
      sw=!sw;
      if (!sub.isEmpty())
        res.add(sub);
    }
    return res;
  }
}