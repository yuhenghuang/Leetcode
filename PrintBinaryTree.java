import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;
import java.util.Queue;
import java.util.ArrayDeque;
//import java.util.Set;
//import java.util.HashSet;

public class PrintBinaryTree {
  List<List<String>> res;
  public List<List<String>> printTree(TreeNode root) {
    res = new ArrayList<>();
    List<Map<Integer, Integer>> tree = new ArrayList<>();
    Queue<Pair> queue = new ArrayDeque<>();
    if (root!=null) queue.add(new Pair(root, 0));
    int m=0;
    while (!queue.isEmpty()) {
      int N = queue.size();
      tree.add(new HashMap<>());
      while (N-->0) {
        Pair p = queue.poll();
        TreeNode node = p.node;
        int index = p.index;
        tree.get(m).put(index, node.val);

        if (node.left!=null) queue.add(new Pair(node.left, index*2));
        if (node.right!=null) queue.add(new Pair(node.right, index*2+1));
      }
      m++;
    }
    for (int i=0; i<m; ++i) res.add(new ArrayList<>());
    int n = (int) Math.pow(2, m)-1;
    List<Integer> indeces = new ArrayList<>();
    for (int j=0; j<n; j++)
      if (j%2==0)
        indeces.add(j);

    
    for (int i=m-1; i>=0; --i) {
      Map<Integer, Integer> seen = new HashMap<>();
      for (int index : tree.get(i).keySet())
        seen.put(indeces.get(index), index);

      for (int j=0; j<n; ++j) {
        if (seen.containsKey(j)){
          res.get(i).add(String.valueOf(tree.get(i).get(seen.get(j))));
        }
        else res.get(i).add("");
      }
      
      List<Integer> indecesNew = new ArrayList<>();
      for (int k=0; k<indeces.size()-1; k+=2) 
        indecesNew.add((indeces.get(k)+indeces.get(k+1))/2);
      indeces = indecesNew;
    }
    return res;
  }

  class Pair {
    TreeNode node;
    int index;
    Pair(TreeNode n, int i) {
      node = n;
      index = i;
    }
  }
}