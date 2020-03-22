import java.util.*;

public class TreeInorderTraversal {
  public List<Integer> inorderTraversal(TreeNode root) {
    List<Integer> res = new ArrayList<>();
    Stack<TreeNode> stack = new Stack<>();
    while (root!=null || !stack.isEmpty()) {
      while (root!=null) {
        stack.push(root);
        root=root.left;
      }
      root=stack.pop();
      res.add(root.val);
      root=root.right;
    }
    return res;
  }


  public List<Integer> inorderTraversal_old(TreeNode root) {
    List<Integer> res = new ArrayList<>();
    Stack<TreeNode> stack = new Stack<>();
    do {
      while(root!=null) {
        stack.push(root);
        root=root.left;
      }

      while(!stack.isEmpty() && stack.peek().right==null) 
        res.add(stack.pop().val);
      
      if (!stack.isEmpty()) {
        root=stack.pop();
        res.add(root.val);
        root=root.right;
        stack.push(root);
      }
    } while (!stack.isEmpty());
    return res;
  }
}