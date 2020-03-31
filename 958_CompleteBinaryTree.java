import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

class CompleteBinaryTree {
  public boolean isCompleteTreeSlow(TreeNode root) {
    Queue<TreeNode> queue = new ArrayDeque<>();
    List<Boolean> list = new ArrayList<>();
    if (root!=null) {
      queue.offer(root);
      list.add(true);
    }

    while(!queue.isEmpty()) {
      root = queue.poll();
      if (root.left!=null) {
        queue.offer(root.left);
        list.add(true);
      }
      else list.add(false);

      if (root.right!=null) {
        queue.offer(root.right);
        list.add(true);
      }
      else list.add(false);

    }

    for (int i=1; i<list.size(); ++i) 
      if (!list.get(i-1) && list.get(i))
        return false;
    return true;
  }
}