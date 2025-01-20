import java.util.*;

public class BottomLeftTreeValue {
  public int findBottomLeftValue(TreeNode root) {
    Queue<TreeNode> queue = new ArrayDeque<>();
    if (root!=null) queue.offer(root);
    while (!queue.isEmpty()) {
      root = queue.poll();
      if (root.right!=null) queue.offer(root.right);
      if (root.left!=null) queue.offer(root.left);
    }
    return root.val;
  }
}