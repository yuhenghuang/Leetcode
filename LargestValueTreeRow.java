import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.Map;
import java.util.HashMap;

public class LargestValueTreeRow {

  Map<Integer, Integer> map;
  public List<Integer> largestValues(TreeNode root) {
    List<Integer> res = new ArrayList<>();
    map = new HashMap<>();
    for (int i=0; i<map.size()-1; i++) res.add(map.get(i));
    return res;
  }

  public void dfs(TreeNode root, int layer) {
    if (root==null) return;
    map.put(layer, root.val);

    dfs(root.left, layer+1);
    dfs(root.right, layer+1);
  }

  void safePut(int layer, int val) {
    if (map.containsKey(val)) map.put(layer, Math.max(map.get(layer), val));
    else map.put(layer, val);
  }

  public List<Integer> largestValues_bfs(TreeNode root) {
    List<Integer> res = new ArrayList<>();
    Queue<TreeNode> queue = new ArrayDeque<>();
    
    if (root!=null) queue.add(root);
    while (!queue.isEmpty()){
      int N=queue.size();
      int temp=Integer.MIN_VALUE;
      while (N-->0) {
        TreeNode node = queue.poll();
        temp=Math.max(temp, node.val);

        if (node.left!=null) queue.add(node.left);
        if (node.right!=null) queue.add(node.right);
      }
      res.add(temp);
    }
    return res;
  }
}