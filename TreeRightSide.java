import java.util.List;
import java.util.ArrayList;
import java.util.Queue;
import java.util.ArrayDeque;


public class TreeRightSide {
  public List<Integer> rightSideView(TreeNode root) {
    List<Integer> res = new ArrayList<>();
    Queue<TreeNode> queue = new ArrayDeque<>();
    if (root!=null) queue.add(root);
    
    int N;
    TreeNode node;
    while (!queue.isEmpty()) {
      N=queue.size();
      res.add(queue.peek().val);
      while (N-->0) {
        node = queue.poll();
        if (node.right!=null) queue.add(node.right);
        if (node.left!=null) queue.add(node.left);
      }
    }
    return res;
  }
}