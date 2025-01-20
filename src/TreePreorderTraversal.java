import java.util.List;
import java.util.ArrayList;
import java.util.Stack;

public class TreePreorderTraversal {
  public List<Integer> preorderTraversal(TreeNode root) {
    Stack<TreeNode> stack = new Stack<>();
    List<Integer> res = new ArrayList<>();

    if (root!=null) stack.push(root);

    while (!stack.isEmpty()) {
      TreeNode node = stack.pop();
      if (node!=null) {
        res.add(node.val);

        stack.push(node.right);
        stack.push(node.left);
      }
    }
    return res;
  }
}