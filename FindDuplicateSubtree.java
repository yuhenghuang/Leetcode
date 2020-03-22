import java.util.*;

public class FindDuplicateSubtree {
  int t;
  Map<String, Integer> trees;
  Map<Integer, Integer> count;
  List<TreeNode> ans;
  public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
    t = 1;
    trees = new HashMap<>();
    count = new HashMap<>();
    ans = new ArrayList<>();
    lookup(root);
    return ans;
  }

  public int lookup(TreeNode node) {
    if (node==null) return 0;
    String serial = node.val + "," + lookup(node.left) + "," +lookup(node.right);
    int uid = trees.computeIfAbsent(serial, x -> t++);
    count.put(uid, count.getOrDefault(uid, 0)+1);
    if (count.get(uid)==2)
      ans.add(node);
    return uid;
  }
  

  Map<TreeNode, String> map;
  public List<TreeNode> findDuplicateSubtreesDFS(TreeNode root) {
    map = new HashMap<>();
    List<TreeNode> res = new ArrayList<>();
    serialize(root);

    Set<String> dup = new HashSet<>();
    Set<String> visited = new HashSet<>();
    for (TreeNode node : map.keySet()) {
      String s = map.get(node);
      if (!dup.contains(s))
        dup.add(s);
      else if (!visited.contains(s)) {
        res.add(node);
        visited.add(s);
      }
    }
    return res;
  }

  public String serialize(TreeNode node) {
    if (node==null) return "n";
    String s = Integer.toString(node.val) + serialize(node.left) + serialize(node.right);
    map.put(node, s);
    return s;
  }
}