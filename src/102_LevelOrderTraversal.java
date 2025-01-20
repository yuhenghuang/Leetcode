import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

class LevelOrderTraversal {
  List<List<Integer>> res;
  public List<List<Integer>> levelOrder(TreeNode root) {
    res = new ArrayList<>();
    dfs(root, 0);
    return res;
  }
  private void dfs(TreeNode node, int degree) {
    if (node==null) return;
    if (degree==res.size())
      res.add(new ArrayList<>());

    res.get(degree).add(node.val);
    dfs(node.left, degree+1);
    dfs(node.right, degree+1);
  }

  public List<List<Integer>> levelOrderBFS(TreeNode root) {
    List<List<Integer>> res = new ArrayList<>();
    Queue<TreeNode> queue = new ArrayDeque<>();
    if (root!=null)
      queue.offer(root);

    while (!queue.isEmpty()) {
      int N = queue.size();
      List<Integer> temp = new ArrayList<>();
      while (N-->0) {
        root = queue.poll();
        temp.add(root.val);
        if (root.left!=null) queue.offer(root.left);
        if (root.right!=null) queue.offer(root.right);
      }
      res.add(temp);
    }
    return res;
  }
}