import java.util.List;
import java.util.ArrayList;
//import java.util.Queue;
//import java.util.ArrayDeque;
import java.util.Stack;

public class TreePostorderTraversal {
  public List<Integer> postorderTraversal(TreeNode root) {
    List<Integer> res = new ArrayList<>();
    Stack<TreeNode> stack = new Stack<>();

    do {
      while (root!=null) {
        stack.push(root);
        root=root.left;
      }

      while (!stack.isEmpty() && stack.peek().right==null) res.add(stack.pop().val);

      if (!stack.isEmpty()) {
        root=stack.peek();
        TreeNode right = root.right;
        root.right=null;
        
        root=right;
      }
    } while (!stack.isEmpty());

    return res;
  }
}