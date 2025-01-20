import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.SortedSet;
import java.util.TreeSet;

class VerticalTraversalofTree {
  Map<Integer, Map<Integer, List<Integer>>> map;
  public List<List<Integer>> verticalTraversal(TreeNode root) {
    List<List<Integer>> res = new ArrayList<>();
    map = new HashMap<>();
    dfs(root, 0, 0);
    SortedSet<Integer> hors = new TreeSet<>(map.keySet());
    for (int x : hors) {
      Map<Integer, List<Integer>> ys = map.get(x);
      SortedSet<Integer> vets = new TreeSet<>(ys.keySet());

      List<Integer> res_temp = new ArrayList<>();
      for (int y : vets) {
        List<Integer> point = ys.get(y);
        Collections.sort(point);
        res_temp.addAll(point);
      }
      res.add(res_temp);
    }
    return res;
  }

  private void dfs(TreeNode node, int vet, int hor) {
    if (node==null) return;

    if (!map.containsKey(hor))
      map.put(hor, new HashMap<>());
    Map<Integer, List<Integer>> vertical = map.get(hor);

    if (!vertical.containsKey(vet))
      vertical.put(vet, new ArrayList<>());
    vertical.get(vet).add(node.val);
    dfs(node.left, vet+1, hor-1);
    dfs(node.right, vet+1, hor+1);
  }
}